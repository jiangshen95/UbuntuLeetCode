class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        return 0 if n == 0 else n//5 + self.trailingZeroes(n // 5)

if __name__=='__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.trailingZeroes(n))
