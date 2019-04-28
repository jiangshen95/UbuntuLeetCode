class Solution:
    def findTargetSumWays(self, nums: list, S: int) -> int:
        def findTargetSum(pos, sum):
            if pos == len(nums):
                return sum == 0
            if (pos, sum) in memo:
                return memo.get((pos, sum))
            res = findTargetSum(pos + 1, sum - nums[pos]) + findTargetSum(pos + 1, sum + nums[pos])
            memo[(pos, sum)] = res
            return res

        memo = {}
        return findTargetSum(0, S)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    S = int(input())
    solution = Solution()
    print(solution.findTargetSumWays(nums, S))
