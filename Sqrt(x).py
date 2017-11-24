# 牛顿迭代法
class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        r = x
        while r*r > x:
            r = (r+x//r)//2
        return r
        
if __name__=='__main__':
    x = int(input())
    solution = Solution()
    print(solution.mySqrt(x))
