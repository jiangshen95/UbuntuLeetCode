class Solution:
    def frequencySort(self, s: str) -> str:
        m = {}
        for c in s:
            if c in m:
                m[c] += 1
            else:
                m[c] = 1
        chars = [''] * (len(s) + 1)
        for key, value in m.items():
            chars[value] += key * value
        result = ''
        for i in range(len(chars) - 1, -1, -1):
            result += chars[i]
        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.frequencySort(s))
