class Solution:
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        mask = 2147483647
        while (m & mask) != (n & mask):
            mask <<= 1
        return m & mask
        
if __name__ == '__main__':
    m = int(raw_input())
    n = int(raw_input())
    solution = Solution()
    print(solution.rangeBitwiseAnd(m, n))
