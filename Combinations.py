class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        def getCombine(start, n, k, result, one):
            if k==0:
                new = one
                result.append(new)
            else:
                for i in range(start, n+1):
                    getCombine(i+1, n, k-1, result, one+[i])
        result = []
        one = []
        getCombine(1, n, k, result, one)
        return result
        
if __name__=='__main__':
    n = int(input())
    k = int(input())
    solution = Solution()
    result = solution.combine(n, k)
    print(result)
