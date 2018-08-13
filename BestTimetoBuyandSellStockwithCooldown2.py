class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n == 0:
            return 0
        buy = -2147483648
        pre_sell = 0
        sell = 0
        for price in prices:
            pre_buy = buy
            buy = max(pre_sell - price, pre_buy)
            pre_sell = sell
            sell = max(pre_buy + price, pre_sell)
        return sell


if __name__ == '__main__':
    prices = [int(price) for price in input().split()]
    solution = Solution()
    print(solution.maxProfit(prices))
