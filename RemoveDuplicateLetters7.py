class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        m = {v: i for i, v in enumerate(s)}
        result = ''
        for i, c in enumerate(s):
            if c not in result:
                while result and result[-1] > c and i < m[result[-1]]:
                    result = result[: -1]
                result += c
        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeDuplicateLetters(s))
