import collections


class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        return list(collections.Counter(t) - collections.Counter(s))[0]


if __name__ == '__main__':
    s = input()
    t = input()
    solution = Solution()
    print(solution.findTheDifference(s, t))
