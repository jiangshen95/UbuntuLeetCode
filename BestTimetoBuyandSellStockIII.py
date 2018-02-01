class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy1 = -1000000
        sell1 = 0
        buy2 = -1000000
        sell2 = 0
        for price in prices:
            buy1 = max(buy1, -price)
            sell1 = max(sell1, buy1+price)
            buy2 = max(buy2, sell1-price)
            sell2 = max(sell2, buy2+price)
        return sell2
        
if __name__=='__main__':
    prices = list(input())
    solution = Solution()
    print(solution.maxProfit(prices))
