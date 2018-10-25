class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        diff = 0
        diff += ord(t[-1])
        for i in range(len(s)):
            diff -= ord(s[i])
            diff += ord(t[i])
        return chr(diff)


if __name__ == '__main__':
    s = input()
    t = input()
    solution = Solution()
    print(solution.findTheDifference(s, t))
