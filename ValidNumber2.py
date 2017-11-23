class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.strip()
        has_dot = False
        has_exp = False
        has_dig = False
        
        for i in range(len(s)):
            if s[i]=='.':
                if has_dot or has_exp:
                    return False
                has_dot = True
            elif s[i]=='e':
                if (not ((not has_exp) and (i>0 and s[i-1]!='+' and s[i-1]!='-') and has_dig)) or i==len(s)-1:
                    return False
                has_exp = True
            elif s[i]=='+' or s[i]=='-':
                if (not (i==0 or (i>0 and s[i-1]=='e'))) or i==len(s)-1:
                    return False
            elif s[i].isdigit():
                has_dig = True
            else:
                return False
                
        return has_dig
            
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    print(solution.isNumber(s))

