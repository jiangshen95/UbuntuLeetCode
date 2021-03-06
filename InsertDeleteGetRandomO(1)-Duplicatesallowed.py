import random


class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.locs = {}
        self.nums = []
        self.indices = {}

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        ret = False
        if val not in self.locs:
            ret = True
            self.locs[val] = []
        self.nums.append(val)
        self.locs[val].append(len(self.nums) - 1)
        self.indices[len(self.nums) - 1] = len(self.locs[val]) - 1
        return ret

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.locs:
            return False
        index = self.locs[val][-1]
        self.locs[val].pop()
        if not self.locs[val]:
            self.locs.pop(val)
        if index < len(self.nums) - 1:
            last = self.nums[-1]
            self.nums[index] = self.nums[-1]
            self.locs[last][self.indices[len(self.nums) - 1]] = index
            self.indices[index] = self.indices[len(self.nums) - 1]
            self.indices.pop(len(self.nums) - 1)
        self.nums.pop()
        return True

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        return self.nums[random.randint(0, len(self.nums) - 1)]


if __name__ == '__main__':
    obj = RandomizedCollection()
    obj.insert(1)
    obj.remove(1)
    obj.insert(2)
    print(obj.getRandom())
