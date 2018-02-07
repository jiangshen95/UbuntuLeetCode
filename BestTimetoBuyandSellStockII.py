class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        maxprofit = 0
        for i in range(1, len(prices)):
            if prices[i]>prices[i-1]:
                maxprofit += prices[i]-prices[i-1]
        return maxprofit
        
if __name__=='__main__':
    prices = list(input())
    solution = Solution()
    print(solution.maxProfit(prices))
