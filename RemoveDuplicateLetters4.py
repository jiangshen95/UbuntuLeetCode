class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        m = {}
        for ch in s:
            if ch in m:
                m[ch] += 1
            else:
                m[ch] = 1
        visited = {}
        result = []
        for ch in s:
            m[ch] -= 1
            if ch in visited:
                continue
            while result and result[-1] > ch and m[result[-1]] > 0:
                del visited[result[-1]]
                result.pop()
            result.append(ch)
            visited[ch] = 1
        return ''.join(result)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeDuplicateLetters(s))
