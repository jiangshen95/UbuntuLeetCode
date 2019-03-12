# can't pass OJ too. I don't know why? It's hard to understand.

class LFUCache:
    class Node:
        def __init__(self, key=-1, value=-1, stamp=-1, freq=0):
            self.key = key
            self.value = value
            self.stamp = stamp
            self.freq = freq

    def __swap(self, index1, index2):
        self.pq[index1], self.pq[index2] = self.pq[index2], self.pq[index1]
        self.m[self.pq[index1].key] = index1
        self.m[self.pq[index2].key] = index2

    def __sink(self, index):
        left, right, target = index * 2, index * 2 + 1, index
        if left < len(self.pq) and self.pq[left].freq <= self.pq[target].freq:
            target = left
        if right < len(self.pq) and (self.pq[right].freq < self.pq[target].freq or
                                     (self.pq[right].freq == self.pq[target].freq and
                                     self.pq[right].stamp < self.pq[target].stamp)):
            target = right
        if target != index:
            self.__swap(target, index)
            self.__sink(target)

    def __swim(self, index):
        par = index // 2
        while par > 0 and self.pq[par].freq > self.pq[index].freq:
            self.__swap(par, index)
            index = par
            par = index // 2

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.stamp = 0
        self.pq = [self.Node()]
        self.m = {}

    def get(self, key: int) -> int:
        if key not in self.m:
            return -1
        self.stamp += 1
        index = self.m[key]
        value = self.pq[index].value
        self.pq[index].freq += 1
        self.pq[index].stamp = self.stamp
        self.__sink(index)
        return value

    def put(self, key: int, value: int) -> None:
        if key in self.m:
            self.pq[self.m[key]].value = value
            self.get(key)
        elif self.capacity > 0:
            self.capacity -= 1
            self.stamp += 1
            self.pq.append(self.Node(key, value, self.stamp, 1))
            self.m[key] = len(self.pq) - 1
            self.__swim(len(self.pq) - 1)
        else:
            if not self.m:
                return
            del self.m[self.pq[1].key]
            self.pq[1] = self.Node(key, value, self.stamp, 1)
            self.m[key] = 1
            self.__sink(1)


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
