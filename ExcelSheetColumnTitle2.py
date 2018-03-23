class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        return "" if n == 0 else self.convertToTitle((n-1)//26) + chr(ord('A') + (n-1)%26)
    
if __name__=='__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.convertToTitle(n))
