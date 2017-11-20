class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        count=0
        for i in range(len(s)-1,-1,-1):
            if s[i]==' ':
                if count==0:
                    continue
                break
            count+=1
        return count
        
        
if __name__=='__main__':
    s = raw_input()
    solution=Solution()
    print(solution.lengthOfLastWord(s))
