class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n == 0:
            return 0
        buy, sell, rest = [0] * n, [0] * n, [0] * n
        for i in range(n):
            if i == 0:
                buy[i] = -prices[i]
            else:
                buy[i] = max(rest[i - 1] - prices[i], buy[i - 1])
                sell[i] = max(buy[i - 1] + prices[i], sell[i - 1])
                rest[i] = max(sell[i - 1], rest[i - 1])
        return sell[-1]


if __name__ == '__main__':
    prices = [int(price) for price in input().split()]
    solution = Solution()
    print(solution.maxProfit(prices))
