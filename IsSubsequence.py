class Solution:
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        indexT = 0
        for ch in s:
            while indexT < len(t) and t[indexT] != ch:
                indexT += 1
            if indexT == len(t):
                return False
            indexT += 1
        return True


if __name__ == '__main__':
    s = input()
    t = input()
    solution = Solution()
    print(solution.isSubsequence(s, t))
