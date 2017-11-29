class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<3:
            return n
        a = 1
        b = 2
        for i in range(3, n+1):
            fib = a+b
            a = b
            b = fib
        return fib
        
if __name__=='__main__':
    n = int(input())
    solution = Solution()
    print(solution.climbStairs(n))
