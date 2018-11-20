class Solution:
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        dp = {}
        dp[0] = set()
        dp[0].add(0)
        for stone in stones:
            if stone in dp:
                for k in dp[stone]:
                    if k - 1 > 0:
                        if stone + k - 1 not in dp:
                            dp[stone + k - 1] = set()
                        dp[stone + k - 1].add(k - 1)
                    if stone + k not in dp:
                        dp[stone + k] = set()
                    dp[stone + k].add(k)
                    if stone + k + 1 not in dp:
                        dp[stone + k + 1] = set()
                    dp[stone + k + 1].add(k + 1)
        return stones[-1] in dp and len(dp[stones[-1]]) > 0


if __name__ == '__main__':
    stones = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.canCross(stones))
