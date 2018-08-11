import math

class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        if not nums:
            return
        self.nums = nums
        # l = math.sqrt(len(nums))
        # n = math.ceil(len(nums) / l)
        n = math.ceil(math.sqrt(len(nums)))
        self.b = [0] * n
        for i in range(len(nums)):
            # self.b[math.floor(i / n)] += nums[i]
            self.b[i // n] += nums[i]

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        # self.b[math.floor(i / len(self.b))] += val - self.nums[i]
        self.b[i // len(self.b)] += val - self.nums[i]
        self.nums[i] = val

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        # begin = math.floor(i / len(self.b))
        # end = math.floor(j / len(self.b))
        begin = i // len(self.b)
        end = j // len(self.b)
        sum = 0
        if begin == end:
            for k in range(i, j + 1):
                sum += self.nums[k]
        else:
            for k in range(begin + 1, end):
                sum += self.b[k]
            for k in range(i, (begin + 1) * len(self.b)):
                sum += self.nums[k]
            for k in range(end * len(self.b), j + 1):
                sum += self.nums[k]
        return sum


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    arr = NumArray(nums)
    print(arr.sumRange(0, 2))
    arr.update(1, 2)
    print(arr.sumRange(0, 2))
