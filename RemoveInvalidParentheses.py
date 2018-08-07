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
        level = {s}
        while True:
            valid = []
            for s in level:
                if isValid(s):
                    valid.append(s)
            if valid:
                return valid
            level = {s[: i] + s[i + 1:] for s in level for i in range(len(s))}


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeInvalidParentheses(s))
