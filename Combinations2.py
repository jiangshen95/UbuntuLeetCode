class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        if k==0:
            return [[]]
        else:
            return [pre+[i] for i in range(1, n+1) for pre in self.combine(i-1, k-1)]
        
if __name__=='__main__':
    n = int(input())
    k = int(input())
    solution = Solution()
    result = solution.combine(n, k)
    print(result)
