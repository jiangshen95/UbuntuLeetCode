class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        title = ""
        while n:
            title = chr(ord('A') + (n-1)%26) + title
            n = (n-1)//26
        return title
    
if __name__=='__main__':
    n = int(raw_input())
    solution = Solution()
    print(solution.convertToTitle(n))
