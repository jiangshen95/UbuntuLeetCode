class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        letters = 'abcdefghijklmnopqrstuvwxyz'
        index = [s.index(ch) for ch in letters if s.count(ch) == 1]
        return min(index) if index else -1


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.firstUniqChar(s))
