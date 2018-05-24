class Solution:
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        count, q, x = 0, n, 1
        while q > 0:
            d = q % 10
            q //= 10
            count += q * x
            if d == 1:
                count += n % x + 1
            if d > 1:
                count += x
            x *= 10
                
            
        return count
        
if __name__ == '__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.countDigitOne(n))
