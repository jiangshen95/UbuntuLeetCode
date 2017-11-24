class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==0:
            return x
        left = 1
        right = x
        while(left<=right):
            mid = left+(right-left)//2
            if mid*mid<=x:
                res = mid
                left = mid+1
            else:
                right = mid-1
        return res
        
if __name__=='__main__':
    x = int(input())
    solution = Solution()
    print(solution.mySqrt(x))
