class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        try:
            float(s.strip())
            return True
        except:
            return False
            
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    print(solution.isNumber(s))
