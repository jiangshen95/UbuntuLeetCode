class Solution:
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        count, a, b = 0, 1, 1
        while n > 0:
            count += (n + 8) // 10 * a + (n % 10 == 1) * b
            b += n % 10 * a
            a *= 10
            n //= 10
        return count
        
if __name__ == '__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.countDigitOne(n))
