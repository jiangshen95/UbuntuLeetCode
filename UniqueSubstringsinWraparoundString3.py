class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        counts = {i: 0 for i in p}
        length = 0
        result = 0
        for i in range(len(p)):
            if i > 0 and p[i - 1] + p[i] not in 'abcdefghijklmnopqrstuvwxyza':
                length = 0
            length += 1
            if length > counts[p[i]]:
                result += length - counts[p[i]]
                counts[p[i]] = length
        return result


if __name__ == '__main__':
    p = input()
    solution = Solution()
    print(solution.findSubstringInWraproundString(p))
