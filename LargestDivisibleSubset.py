class Solution:
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        nums.sort()

        n = len(nums)
        dp = [1] * n
        path = [-1] * n
        index = -1
        max_size = 0

        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        path[i] = j
            if dp[i] > max_size:
                max_size = dp[i]
                index = i

        result = []
        while index >= 0:
            result = [nums[index]] + result
            index = path[index]

        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.largestDivisibleSubset(nums))
