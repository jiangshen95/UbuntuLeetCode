class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        if not nums:
            return
        self.nums = nums
        self.n = len(nums)
        self.bit = [0] * (self.n + 1)
        for i in range(0, self.n):
            self.init(i, nums[i])

    def init(self, i, val):
        i += 1
        while i <= self.n:
            self.bit[i] += val
            i += (i & -i)
            print(i)

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        diff = val - self.nums[i]
        self.nums[i] = val
        self.init(i, diff)

    def getSum(self, i):
        sum = 0
        i += 1
        while i > 0:
            sum += self.bit[i]
            i -= (i & -i)
        return sum

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.getSum(j) - self.getSum(i - 1)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    arr = NumArray(nums)
    print(arr.sumRange(0, 2))
    arr.update(1, 2)
    print(arr.sumRange(0, 2))
