class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        def coinChange(amount, index, count):
            if index < 0 or count >= self.total - 1:
                return
            c = amount // coins[index]
            for i in range(c, -1, -1):
                newCount = count + i
                rem = amount - coins[index] * i
                if rem > 0 and newCount < self.total:
                    coinChange(rem, index - 1, newCount)
                elif newCount < self.total:
                    self.total = newCount
                elif newCount >= self.total - 1:
                    break

        self.total = amount + 1
        if amount == 0:
            return 0
        coins = sorted(coins)
        coinChange(amount, len(coins) - 1, 0)
        return -1 if self.total == amount + 1 else self.total


if __name__ == '__main__':
    coins = [int(coin) for coin in input().split()]
    amount = int(input())
    solution = Solution()
    print(solution.coinChange(coins, amount))
