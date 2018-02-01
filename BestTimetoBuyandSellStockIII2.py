class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        local = [0]*3
        cur = [0]*3
        for i in range(1, len(prices)):
            for j in range(2, 0, -1):
                local[j] = max(local[j]+prices[i]-prices[i-1], cur[j-1]+max(0, prices[i]-prices[i-1]))
                cur[j] = max(cur[j], local[j])
        return cur[2]
        
if __name__=='__main__':
    prices = list(input())
    solution = Solution()
    print(solution.maxProfit(prices))
