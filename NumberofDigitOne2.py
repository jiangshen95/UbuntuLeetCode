class Solution:
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        count, k = 0, 1
        while k <= n:
            d = n % k
            m = n // k
            count += (m + 8) // 10 * k + ((d + 1) if m % 10 == 1 else 0)
            k *= 10
        return count
        
if __name__ == '__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.countDigitOne(n))
