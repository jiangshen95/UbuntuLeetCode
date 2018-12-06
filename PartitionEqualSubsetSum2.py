class Solution:
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        target = sum(nums)
        if target % 2 == 1:
            return False
        target //= 2

        bits = 1
        for num in nums:
            bits |= (bits << num)
        print(bits)
        return ((bits >> target) & 1) == 1


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.canPartition(nums))
