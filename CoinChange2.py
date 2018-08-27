class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        def coinChange(value):
            if value == 0:
                return 0
            if value in dp:
                return dp[value]
            cur = 2147483647
            for coin in coins:
                if value >= coin:
                    temp = coinChange(value - coin)
                    if temp >= 0:
                        cur = min(cur, temp + 1)
            if cur != 2147483647:
                dp[value] = cur
            else:
                dp[value] = -1
            return dp[value]

        if amount == 0:
            return 0
        dp = {0: 0}
        return coinChange(amount)


if __name__ == '__main__':
    coins = [int(coin) for coin in input().split()]
    amount = int(input())
    solution = Solution()
    print(solution.coinChange(coins, amount))
