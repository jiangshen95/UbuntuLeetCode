class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        mem = set()
        while n != 1:
            m = 0
            while n > 0:
                m += (n%10) * (n%10)
                n //= 10
            n = m
            if n in mem:
                return False
            else:
                mem.add(n)
        return True
        
if __name__=='__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.isHappy(n))
