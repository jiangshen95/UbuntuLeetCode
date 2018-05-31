class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        dic = {}
        for c in s:
            if c not in dic:
                dic[c] = 0
            dic[c] += 1
        for c in t:
            if c not in dic:
                return False
            if dic[c] == 0:
                return False
            dic[c] -= 1
        return True

if __name__ == '__main__':
    s = input()
    t = input()
    solution = Solution()
    print(solution.isAnagram(s, t))
