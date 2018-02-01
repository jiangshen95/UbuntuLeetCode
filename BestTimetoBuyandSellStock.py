class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minshell = 0
        maxprofit = 0
        for i in range(len(prices)):
            if i==0:
                minshell = prices[i]
            else:
                if prices[i]<minshell:
                    minshell = prices[i]
                if prices[i]-minshell>maxprofit:
                    maxprofit = prices[i]-minshell
        return maxprofit
        
if __name__=='__main__':
    prices = list(input())
    solution = Solution()
    print(solution.maxProfit(prices))
