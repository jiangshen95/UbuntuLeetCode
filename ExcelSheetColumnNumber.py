class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        number = 0
        for ch in s:
            number = number * 26 + ord(ch) - ord('A') + 1
        return number
        
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    print(solution.titleToNumber(s))
