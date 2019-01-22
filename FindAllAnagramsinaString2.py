class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if not s or len(s) < len(p):
            return []
        from collections import Counter
        result = []
        pCounter = Counter(p)
        sCounter = Counter(s[: len(p) - 1])
        for i in range(len(p) - 1, len(s)):
            sCounter[s[i]] += 1
            if sCounter == pCounter:
                result.append(i - len(p) + 1)
            sCounter[s[i - len(p) + 1]] -= 1
            if sCounter[s[i - len(p) + 1]] == 0:
                del sCounter[s[i - len(p) + 1]]
        return result


if __name__ == '__main__':
    s = input()
    p = input()
    solution = Solution()
    print(solution.findAnagrams(s, p))
