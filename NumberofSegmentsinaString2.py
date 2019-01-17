class Solution:
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        for i in range(len(s)):
            if s[i] != ' ' and (i == len(s) - 1 or s[i + 1] == ' '):
                count += 1
        return count


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.countSegments(s))
