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
        result = ''
        for i in range(len(s)):
            if m[s[i]] == 1:
                result += s[i]
            elif m[s[i]] == -1:
                continue
            else:
                m2 = {}
                f = False
                for j in range(i + 1, len(s)):
                    if s[j] > s[i]:
                        if s[j] in m2:
                            m2[s[j]] += 1
                        else:
                            m2[s[j]] = 1
                        if m2[s[j]] == m[s[j]]:
                            f = True
                            result += s[i]
                            m[s[i]] = -1
                            break
                    elif s[j] < s[i] and m[s[j]] != -1:
                        f = True
                        m[s[i]] -= 1
                        break
                if not f:
                    result += s[i]
                    m[s[i]] = -1
        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeDuplicateLetters(s))
