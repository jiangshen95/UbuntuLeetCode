class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m>n:
            uniquePaths(n, m)
        cur = [1 for i in range(m)]
        for j in range(1, n):
            for i in range(1,m):
                cur[i] += cur[i-1]
        return cur[m-1]
        
if __name__=='__main__':
    m = int(input())
    n = int(input())
    solution = Solution()
    print(solution.uniquePaths(m, n))
