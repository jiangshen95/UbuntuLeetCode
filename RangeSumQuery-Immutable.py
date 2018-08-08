class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.sums = [0] * (len(nums) + 1)
        for i in range(0, len(nums)):
            self.sums[i + 1] = self.sums[i] + nums[i];

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j + 1] - self.sums[i]


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    arr = NumArray(nums)
    print(arr.sumRange(0, 2))
    print(arr.sumRange(2, 5))
    print(arr.sumRange(0, 5))