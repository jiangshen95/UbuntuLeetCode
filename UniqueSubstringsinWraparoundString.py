class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        counts = {i: 1 for i in p}
        length = 1
        for i in range(len(p)):
            if i > 0 and p[i - 1] + p[i] in 'abcdefghijklmnopqrstuvwxyza':
                length += 1
            else:
                length = 1
            counts[p[i]] = max(counts[p[i]], length)
        return sum(counts.values())


if __name__ == '__main__':
    p = input()
    solution = Solution()
    print(solution.findSubstringInWraproundString(p))
