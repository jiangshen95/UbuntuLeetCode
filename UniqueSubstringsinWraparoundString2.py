class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        counts = {i: 1 for i in p}
        length = 1
        for i, j in zip(p, p[1:]):
            length = length + 1 if (ord(j) - ord(i)) % 26 == 1 else 1
            counts[j] = max(counts[j], length)
        return sum(counts.values())


if __name__ == '__main__':
    p = input()
    solution = Solution()
    print(solution.findSubstringInWraproundString(p))
