class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        def restoreIp(result, one, s, curr, count):
            if count>=4:
                return
            
            for i in range(curr, min(curr+3, len(s))):
                if s[curr]=='0' and i>curr:
                    break
                if int(s[curr: i+1])<256:
                    if i==len(s)-1 and count==3:
                        result += [one+s[curr: i+1]]
                    else:
                        restoreIp(result, one+s[curr: i+1]+'.', s, i+1, count+1)
                else:
                    break
        
        result = []
        
        restoreIp(result, "", s, 0, 0)
                        
        return result
        
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    result = solution.restoreIpAddresses(s)
    print(result)
