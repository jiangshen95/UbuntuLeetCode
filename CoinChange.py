class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0
        max_num = amount + 1
        dp = [max_num] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin >= 0:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return -1 if dp[i] == max_num else dp[amount]


if __name__ == '__main__':
    coins = [int(coin) for coin in input().split()]
    amount = int(input())
    solution = Solution()
    print(solution.coinChange(coins, amount))
