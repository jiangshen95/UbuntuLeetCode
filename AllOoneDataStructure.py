class AllOne:

    class Bucket:
        def __init__(self, val):
            self.val = val
            self.pre = None
            self.next = None
            self.keys = set()

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.m = {}
        self.head = self.Bucket(0)
        self.tail = self.Bucket(0)
        self.head.next = self.tail
        self.tail.pre = self.head

    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        if key in self.m:
            cur = self.m[key]
            if cur.next.val != cur.val + 1:
                newBucket = self.Bucket(cur.val + 1)
                newBucket.pre = cur
                newBucket.next = cur.next
                cur.next.pre = newBucket
                cur.next = newBucket
            cur.next.keys.add(key)
            self.m[key] = cur.next
            cur.keys.remove(key)
            if not cur.keys:
                cur.pre.next = cur.next
                cur.next.pre = cur.pre
                cur.next = None
                cur.pre = None
        else:
            if self.head.next.val != 1:
                newBucket = self.Bucket(1)
                newBucket.pre = self.head
                newBucket.next = self.head.next
                self.head.next.pre = newBucket
                self.head.next = newBucket
            self.head.next.keys.add(key)
            self.m[key] = self.head.next

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        if key not in self.m:
            return
        cur = self.m[key]
        if cur.val == 1:
            cur.keys.remove(key)
            if not cur.keys:
                cur.pre.next = cur.next
                cur.next.pre = cur.pre
                cur.pre = None
                cur.next = None
            del self.m[key]
            return

        if cur.val - 1 != cur.pre.val:
            newBucket = self.Bucket(cur.val - 1)
            newBucket.pre = cur.pre
            newBucket.next = cur
            cur.pre.next = newBucket
            cur.pre = newBucket
        cur.pre.keys.add(key)
        self.m[key] = cur.pre
        cur.keys.remove(key)
        if not cur.keys:
            cur.pre.next = cur.next
            cur.next.pre = cur.pre
            cur.pre = None
            cur.next = None

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        if self.tail.pre == self.head:
            return ""
        else:
            return list(self.tail.pre.keys)[0]

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        if self.head.next == self.tail:
            return ''
        else:
            return list(self.head.next.keys)[0]


if __name__ == '__main__':
    obj = AllOne()

    obj.inc('a')
    obj.inc('b')
    obj.inc('b')
    obj.inc('b')
    obj.inc('b')

    obj.dec('b')
    obj.dec('b')

    print(obj.getMaxKey())
    print(obj.getMinKey())
