class Solution:
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        """"
        dp = {}
        for stone in stones:
            dp[stone] = set()
        dp[0].add(1)
        for stone in stones:
            for k in dp[stone]:
                if stone + k == stones[-1]:
                    return True
                if stone + k in stones:
                    if k - 1 > 0:
                        dp[stone + k].add(k - 1)
                    dp[stone + k].add(k)
                    dp[stone + k].add(k + 1)
        return False
        """

        dp = {}
        # for stone in stones:
        #     dp[stone] = set()
        dp[0] = set()
        dp[0].add(1)
        for stone in stones:
            if stone in dp:
                for k in dp[stone]:
                    if stone + k == stones[-1]:
                        return True
                    if stone + k in stones:
                        if stone + k not in dp:
                            dp[stone + k] = set()
                        if k - 1 > 0:
                            dp[stone + k].add(k - 1)
                        dp[stone + k].add(k)
                        dp[stone + k].add(k + 1)
        return False


if __name__ == '__main__':
    stones = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.canCross(stones))
