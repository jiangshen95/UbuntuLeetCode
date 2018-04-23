class Solution:
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        count = 0
        while m != n:
            m >>= 1
            n >>= 1
            count += 1
        return m << count
        
if __name__ == '__main__':
    m = int(raw_input())
    n = int(raw_input())
    solution = Solution()
    print(solution.rangeBitwiseAnd(m, n))
