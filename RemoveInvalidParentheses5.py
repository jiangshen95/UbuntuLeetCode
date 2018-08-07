class Solution:
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def helper(s, last_i, last_j, p):
            cnt = 0
            for i in range(last_i, len(s)):
                if s[i] == p[0]:
                    cnt += 1
                elif s[i] == p[1]:
                    cnt -= 1
                if cnt >= 0:
                    continue
                for j in range(last_j, i + 1):
                    if s[j] == p[1] and (j == last_j or s[j] != s[j - 1]):
                        helper(s[: j] + s[j + 1:], i, j, p)
                return

            temp = ''.join(list(reversed(s)))
            if p[0] == '(':
                helper(temp, 0, 0, ')(')
            else:
                result.append(temp)

        result = []
        helper(s, 0, 0, '()')
        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeInvalidParentheses(s))
