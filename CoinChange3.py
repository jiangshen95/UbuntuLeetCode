class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0
        value1 = [0]
        value2 = []
        visited = [False] * (amount + 1)
        nc = 0
        while value1:
            nc += 1
            for v in value1:
                for coin in coins:
                    temp = v + coin
                    if temp == amount:
                        return nc
                    elif temp < amount and not visited[temp]:
                        value2.append(temp)
                        visited[temp] = True
            value1, value2 = value2, []
        return -1


if __name__ == '__main__':
    coins = [int(coin) for coin in input().split()]
    amount = int(input())
    solution = Solution()
    print(solution.coinChange(coins, amount))
