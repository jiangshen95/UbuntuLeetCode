class Solution:
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        if k > len(prices):
            return self.maxProfit2(prices)
        
        local = [0] * (k + 1)
        globa = [0] * (k + 1)
        for i in range(1, len(prices)):
            for j in range(k, 0, -1):
                local[j] = max(globa[j-1] + max(0, prices[i] - prices[i-1]), local[j] + prices[i] - prices[i-1])
                globa[j] = max(globa[j], local[j])
        return globa[k]
            
    def maxProfit2(self, prices):
        maxprofit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                maxprofit += prices[i] - prices[i-1]
        return maxprofit
        
if __name__ == '__main__':
    k = int(raw_input())
    prices = list(input())
    
    solution = Solution()
    print(solution.maxProfit(k, prices))
