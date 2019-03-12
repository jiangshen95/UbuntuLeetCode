# some problem, can't work

import heapq


class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.m = {}
        self.q = []
        self.stamp = 0

    def get(self, key: int) -> int:
        if key not in self.m:
            return -1
        self.stamp += 1
        self.q.remove(self.m[key])
        times, stamp, value, _ = self.m[key]
        self.m[key] = (times + 1, self.stamp, value, key)
        heapq.heappush(self.q, self.m[key])

        return value

    def put(self, key: int, value: int) -> None:
        self.stamp += 1
        if key in self.m:
            self.q.remove(self.m[key])
            times, stamp, old_value, _ = self.m[key]
            self.m[key] = (times + 1, self.stamp, value, key)
            heapq.heappush(self.q, self.m[key])
            return
        elif self.capacity > 0:
            self.capacity -= 1
        else:
            if not self.m:
                return
            times, stamp, old_value, old_key = heapq.heappop(self.q)
            del self.m[old_key]
        self.m[key] = (1, self.stamp, value, key)
        heapq.heappush(self.q, self.m[key])


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
