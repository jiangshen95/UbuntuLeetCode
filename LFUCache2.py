class LFUCache:
    class Node:
        def __init__(self, count):
            self.count = count
            self.keys = []
            self.next = None
            self.pre = None

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.m = {}
        self.key_node = {}
        self.head = None

    def increaseCount(self, key):
        node = self.key_node[key]
        node.keys.remove(key)
        if not node.next:
            node.next = self.Node(node.count + 1)
            node.next.pre = node
            node.next.keys.append(key)
        elif node.next.count == node.count + 1:
            node.next.keys.append(key)
        else:
            temp = self.Node(node.count + 1)
            temp.keys.append(key)
            temp.pre = node
            temp.next = node.next
            node.next.pre = temp
            node.next = temp
        self.key_node[key] = node.next
        if not node.keys:
            self.remove(node)

    def addNew(self, key):
        if self.head:
            if self.head.count == 1:
                self.head.keys.append(key)
            else:
                new = self.Node(1)
                new.keys.append(key)
                new.next = self.head
                self.head.pre = new
                self.head = new
        else:
            self.head = self.Node(1)
            self.head.keys.append(key)
        self.key_node[key] = self.head

    def removeOld(self):
        if not self.head:
            return
        key = self.head.keys.pop(0)
        del self.m[key]
        if not self.head.keys:
            self.remove(self.head)

    def remove(self, node):
        if not node.pre:
            self.head = node.next
        else:
            node.pre.next = node.next
        if node.next:
            node.next.pre = node.pre

    def get(self, key: int) -> int:
        if key not in self.m:
            return -1
        self.increaseCount(key)
        return self.m[key]

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.m[key] = value
            return
        elif self.capacity > 0:
            self.capacity -= 1
        else:
            if not self.m:
                return
            self.removeOld()
        self.m[key] = value
        self.addNew(key)


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
