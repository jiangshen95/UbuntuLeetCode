class Solution:
    def frequencySort(self, s: str) -> str:
        m = {}
        for c in s:
            if c in m:
                m[c] += 1
            else:
                m[c] = 1
        result = sorted(s, key=lambda x: (m[x], x), reverse=True)
        return ''.join(result)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.frequencySort(s))
