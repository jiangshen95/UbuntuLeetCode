class Solution:
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n % 4 != 0


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.canWinNim(n))
