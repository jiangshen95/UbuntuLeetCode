class Solution:
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        print(s1)
        print(s2)
        if s1==s2:
            return True
        l1 = sorted(list(s1))
        l2 = sorted(list(s2))
        if cmp(l1, l2)!=0:
            return False
        for i in range(1, len(s1)):
            if self.isScramble(s1[0 : i], s2[0 : i]) and self.isScramble(s1[i : len(s1)], s2[i : len(s1)]):
                return True
            if self.isScramble(s1[0 : i], s2[len(s1)-i : len(s1)]) and self.isScramble(s1[i : len(s1)], s2[0 : len(s1)-i]):
                return True
        return False
        
if __name__=='__main__':
    s1 = raw_input()
    s2 = raw_input()
    solution = Solution()
    print(solution.isScramble(s1, s2))
