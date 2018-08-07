class Solution:
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def helper(index, cnt1, cnt2, pair, path):
            if index == len(s):
                if cnt1 == 0 and cnt2 == 0 and pair == 0:
                    result.append(path)
                return
            if s[index] != '(' and s[index] != ')':
                helper(index + 1, cnt1, cnt2, pair, path + s[index])
            else:
                if s[index] == '(':
                    if cnt1 > 0:
                        helper(index + 1, cnt1 - 1, cnt2, pair, path)
                    helper(index + 1, cnt1, cnt2, pair + 1, path + s[index])
                elif s[index] == ')':
                    if cnt2 > 0:
                        helper(index + 1, cnt1, cnt2 - 1, pair, path)
                    if pair > 0:
                        helper(index + 1, cnt1, cnt2, pair - 1, path + s[index])
        result = []
        cnt1 = 0
        cnt2 = 0
        for c in s:
            if c == '(':
                cnt1 += 1
            elif c == ')':
                if cnt1 == 0:
                    cnt2 += 1
                else:
                    cnt1 -= 1
        helper(0, cnt1, cnt2, 0, '')
        result = {t for t in result}
        return list(result)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeInvalidParentheses(s))
