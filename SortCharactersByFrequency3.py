class Solution:
    def frequencySort(self, s: str) -> str:
        m = {}
        for c in s:
            if c in m:
                m[c] += 1
            else:
                m[c] = 1
        from heapq import heappush, heappop
        q = []
        for key, value in m.items():
            heappush(q, (-value, key))
        result = ''
        while q:
            n, c = heappop(q)
            result += c * (-n)
        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.frequencySort(s))
