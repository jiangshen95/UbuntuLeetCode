class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        need = {}
        for ch in t:
            if ch in need:
                need[ch] += 1
            else:
                need[ch] = 1
        print(need)
        counter = len(t)
        begin = 0
        minlen = 0
        result = ""
        for end in range(len(s)):
            if s[end] in need:
                need[s[end]]-=1
                if need[s[end]]>=0:
                    counter-=1
                if counter==0:
                    for i in range(begin, end+1):
                        if s[i] in need:
                            need[s[i]]+=1
                            if need[s[i]]>0:
                                need[s[i]]-=1
                                begin = i
                                break
                    print("begin: %d" % begin)
                    print("end: %d" % end)
                    if minlen>end-begin+1 or minlen==0:
                        minlen = end-begin+1
                        result = s[begin: end+1]
        return result
        
if __name__=='__main__':
    s = raw_input()
    t = raw_input()
    solution = Solution()
    print(solution.minWindow(s, t))
