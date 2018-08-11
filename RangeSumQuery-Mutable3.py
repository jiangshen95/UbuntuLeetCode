class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        if not nums:
            return
        self.n = len(nums)
        self.segmentTree = [0] * (self.n * 2)
        self.build(nums)

    def build(self, nums):
        for i in range(self.n):
            self.segmentTree[i + self.n] = nums[i]
        for i in range(self.n - 1, -1, -1):
            self.segmentTree[i] = self.segmentTree[i * 2] + self.segmentTree[i * 2 + 1]

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        i += self.n
        diff = val - self.segmentTree[i]
        while i > 0:
            self.segmentTree[i] += diff
            i //= 2

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        i += self.n
        j += self.n
        sum = 0
        while i <= j:
            if i % 2 == 1:
                sum += self.segmentTree[i]
                i += 1
            if j % 2 == 0:
                sum += self.segmentTree[j]
                j -= 1
            i //= 2
            j //= 2
        return sum


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    arr = NumArray(nums)
    print(arr.sumRange(0, 2))
    arr.update(1, 2)
    print(arr.sumRange(0, 2))
