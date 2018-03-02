class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.pre = None
        self.next = None
        
class LRUCache:
    
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.begin = None
        self.end = None
        self.hash_map = {}
    
    def update(self, node):
        if node == self.begin:
            return
        if node.pre and node.next:
            node.pre.next = node.next
            node.next.pre = node.pre
            node.next = self.begin
            node.pre = None
            self.begin.pre = node
        elif node == self.end:
            self.end = self.end.pre
            self.end.next = None
            node.next = self.begin
            node.pre = None
            self.begin.pre = node
        self.begin = node
            
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.hash_map:
            cur = self.hash_map[key]
            self.update(cur)
            return cur.value
        else:
            return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.hash_map:
            cur = self.hash_map[key]
            self.update(cur)
            cur.value = value
        else:
            if len(self.hash_map) == self.capacity:
                cur = self.end
                self.update(cur)
                self.hash_map.pop(cur.key)
                cur.key = key
                cur.value = value
                self.hash_map[key] = cur
            else:
                add = Node(key, value)
                if self.begin:
                    add.next = self.begin
                    self.begin.pre = add
                    self.begin = add
                else:
                    self.begin = add
                    self.end = add
                self.hash_map[key] = add
                
if __name__=='__main__':
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(1, 3)
    cache.put(2, 2)
    print(cache.get(1))
    cache.put(3, 3)
    print(cache.get(2))
    cache.put(4, 4)
    print(cache.get(1))
    print(cache.get(3))
    print(cache.get(4))
