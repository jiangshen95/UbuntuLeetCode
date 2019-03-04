class Solution:
    def findContentChildren(self, g, s) -> int:
        g.sort()
        s.sort()
        i, j = 0, 0
        while i < len(g) and j < len(s):
            if g[i] <= s[j]:
                i += 1
            j += 1
        return i


if __name__ == '__main__':
    g = [int(num) for num in input().split()]
    s = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findContentChildren(g, s))
