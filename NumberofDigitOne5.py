class Solution:
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        count, q = 0, n
        lowc, lown = 1, 0
        while q > 0:
            d = q % 10
            q //= 10
            if d == 1:
                count += q % lowc
                count += lown + 1
            elif d == 0:
                count += q * lowc
            elif d > 1:
                count += (q + 1) * lowc
            
            lown += lowc * d
            lowc *= 10
                
            
        return count
        
if __name__ == '__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.countDigitOne(n))
