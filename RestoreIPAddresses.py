class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        def isValid(s):
            if len(s)>3 or len(s)==0 or (s[0]=='0' and len(s)>1) or int(s)>255:
                return False
            else:
                return True
        
        result = []
        
        for i in range(0, min(3, len(s)-3)):
            for j in range(i+1, min(i+4, len(s)-2)):
                for k in range(j+1, min(j+4, len(s)-1)):
                    s1 = s[0:i+1]
                    s2 = s[i+1: j+1]
                    s3 = s[j+1: k+1]
                    s4 = s[k+1: len(s)]
                    if isValid(s1) and isValid(s2) and isValid(s3) and isValid(s4):
                        result += [s1+'.'+s2+'.'+s3+'.'+s4]
                        
        return result
        
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    result = solution.restoreIpAddresses(s)
    print(result)
