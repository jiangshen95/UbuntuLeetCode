class Solution:
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in range(31, -1, -1):
            result <<= 1
            prefix = {num >> i for num in nums}
            result += any(p ^ 1 ^ result in prefix for p in prefix)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findMaximumXOR(nums))
