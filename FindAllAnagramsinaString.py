class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if not s or len(s) < len(p):
            return []
        m1 = [0] * 128
        m2 = [0] * 128
        for i in range(len(p)):
            m1[ord(p[i])] += 1
            m2[ord(s[i])] += 1

        result = []
        if m1 == m2:
            result.append(0)
        for i in range(len(p), len(s)):
            m2[ord(s[i])] += 1
            m2[ord(s[i - len(p)])] -= 1
            if m1 == m2:
                result.append(i - len(p) + 1)
        return result


if __name__ == '__main__':
    s = input()
    p = input()
    solution = Solution()
    print(solution.findAnagrams(s, p))
