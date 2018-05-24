class Solution:
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and (n & (n - 1) == 0)
        
if __name__ == '__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.isPowerOfTwo(n))
