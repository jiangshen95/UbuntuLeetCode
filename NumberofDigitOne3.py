class Solution:
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        count, k = 0, 1
        while k <= n:
            d = k * 10
            count += n // d * k + min(max(n % d - k + 1 ,0), k)
            k *= 10
        return count
        
if __name__ == '__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.countDigitOne(n))
