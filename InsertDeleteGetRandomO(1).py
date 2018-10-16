import random


class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dict = {}
        self.nums = []

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.dict:
            return False
        self.nums.append(val)
        self.dict[val] = len(self.nums) - 1
        return True

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.dict:
            return False
        if self.dict[val] < len(self.nums) - 1:
            index, last = self.dict[val], self.nums[-1]
            self.nums[index], self.nums[-1] = self.nums[-1], self.nums[index]
            self.dict[last] = index
        self.dict.pop(self.nums[-1])
        self.nums.pop()
        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return self.nums[random.randint(0, len(self.nums) - 1)]


if __name__ == '__main__':
    obj = RandomizedSet()
    obj.insert(1)
    obj.insert(2)
    obj.remove(1)
    print(obj.getRandom())
