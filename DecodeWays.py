class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s)==0 or s[0]=='0':
            return 0
        num1 = 1
        num2 = 1
        for i in range(1, len(s)):
            if s[i]=='0':
                num2 = 0
            if int(s[i-1:i+1])<=26:
                num2 = num1+num2
                num1 = num2-num1
            else:
                num1 = num2
        return num2
        
if __name__=='__main__':
    s = raw_input()
    solution=Solution()
    print(solution.numDecodings(s))
