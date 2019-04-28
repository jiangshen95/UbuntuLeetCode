class Solution:
    def findTargetSumWays(self, nums: list, S: int) -> int:
        dp = {0: 1}
        for num in nums:
            t = {}
            for s, cnt in dp.items():
                t[s + num] = t.get(s + num, 0) + cnt
                t[s - num] = t.get(s - num, 0) + cnt
            dp = t
        return dp.get(S, 0)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    S = int(input())
    solution = Solution()
    print(solution.findTargetSumWays(nums, S))
