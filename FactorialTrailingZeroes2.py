class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        r = 0
        while n > 0:
            n = n//5
            r += n
        return r

if __name__=='__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.trailingZeroes(n))
