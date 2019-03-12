class LFUCache:
    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.count = 1
            self.next = None
            self.pre = None

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.minFreq = 0
        self.m = {}
        self.freq = {}

    def remove(self, cur):
        head, tail = self.freq[cur.count][0], self.freq[cur.count][1]
        if head == tail:
            del self.freq[cur.count]
            if self.minFreq == cur.count:
                self.minFreq += 1
        elif cur == head:
            head = head.next
            head.pre = None
            self.freq[cur.count][0] = head
        elif cur == tail:
            tail = tail.pre
            tail.next = None
            self.freq[cur.count][1] = tail
        else:
            cur.pre.next = cur.next
            cur.next.pre = cur.pre

    def add(self, cur):
        if cur.count in self.freq:
            self.freq[cur.count][1].next = cur
            cur.pre = self.freq[cur.count][1]
            cur.next = None
            self.freq[cur.count][1] = cur
        else:
            self.freq[cur.count] = [cur, cur]

    def get(self, key: int) -> int:
        if key not in self.m:
            return -1
        self.remove(self.m[key])
        self.m[key].count += 1
        self.add(self.m[key])
        return self.m[key].value

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.m[key].value = value
            return
        elif self.capacity > 0:
            self.capacity -= 1
        else:
            if not self.m:
                return
            cur = self.freq[self.minFreq][0]
            del self.m[cur.key]
            self.remove(cur)
        self.m[key] = self.Node(key, value)
        self.add(self.m[key])
        self.minFreq = 1


if __name__ == '__main__':
    cache = LFUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))
    cache.put(3, 3)
    print(cache.get(2))
    print(cache.get(3))
    cache.put(4, 4)
    print(cache.get(1))
    print(cache.get(3))
    print(cache.get(4))
