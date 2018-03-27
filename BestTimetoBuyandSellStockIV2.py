class Solution:
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        p = 0
        v = 0
        
        vp_pairs = []
        profits = []
        
        while p < len(prices)-1:
            v = p
            while v < len(prices) - 1 and prices[v] >= prices[v+1]:
                v += 1
            p = v + 1
            while p < len(prices) and prices[p] >= prices[p-1]:
                p += 1
            while len(vp_pairs) > 0 and prices[v] < prices[vp_pairs[-1][0]]:
                profits.append(prices[vp_pairs[-1][1] - 1] - prices[vp_pairs[-1][0]])
                vp_pairs.pop()
            while len(vp_pairs) > 0 and prices[p-1] >= prices[vp_pairs[-1][1]-1]:
                profits.append(prices[vp_pairs[-1][1]-1] - prices[v])
                v = vp_pairs[-1][0]
                vp_pairs.pop()
            vp_pairs.append((v, p))
        while len(vp_pairs) > 0:
            profits.append(prices[vp_pairs[-1][1]-1] - prices[vp_pairs[-1][0]])
            vp_pairs.pop()
        profits.sort()
        i = 0
        result = 0
        while i < k and len(profits) > 0:
            result += profits[-1]
            profits.pop()
            i += 1
            
        return result
            
        
if __name__ == '__main__':
    k = int(raw_input())
    prices = list(input())
    
    solution = Solution()
    print(solution.maxProfit(k, prices))
