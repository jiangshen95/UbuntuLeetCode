import re

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = re.split(r' +', s.strip())
        words.reverse()
        return ' '.join(words)
        
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    print(solution.reverseWords(s))
