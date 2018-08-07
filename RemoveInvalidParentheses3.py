class Solution:
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def isValid(s):
            cnt = 0
            for ch in s:
                if ch == '(':
                    cnt += 1
                elif ch == ')':
                    cnt -= 1
                    if cnt < 0:
                        return False
            return cnt == 0

        def helper(s, start, cnt1, cnt2):
            if cnt1 == 0 and cnt2 == 0:
                if isValid(s):
                    result.append(s)
                return
            for i in range(start, len(s)):
                if i != start and s[i] == s[i - 1]:
                    continue
                else:
                    if cnt1 > 0 and s[i] == '(':
                        helper(s[: i] + s[i + 1:], i, cnt1 - 1, cnt2)
                    elif cnt2 > 0 and s[i] == ')':
                        helper(s[: i] + s[i + 1:], i, cnt1, cnt2 - 1)

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
        helper(s, 0, cnt1, cnt2)

        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeInvalidParentheses(s))
