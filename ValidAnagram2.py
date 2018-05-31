class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dic = [0] * 26
        for c in s:
            dic[ord(c) - ord('a')] += 1
        for c in t:
            dic[ord(c) - ord('a')] -= 1
        for n in dic:
            if n != 0:
                return False
        return True

if __name__ == '__main__':
    s = input()
    t = input()
    solution = Solution()
    print(solution.isAnagram(s, t))
