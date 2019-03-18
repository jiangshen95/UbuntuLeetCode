class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        repeatCnt = [0] * (n1 + 1)
        nextIndex = [0] * (n1 + 1)
        j, count = 0, 0
        for k in range(1, n1 + 1, 1):
            for ch in s1:
                if ch == s2[j]:
                    j += 1
                    if j == len(s2):
                        count += 1
                        j = 0
            repeatCnt[k] = count
            if j in nextIndex:  # 若从 1 开始循环的时候遇到恰好分割的情况可能多循环几次
                start = nextIndex.index(j)
                interval = k - start
                repeat = (n1 - start) // interval
                patternCnt = repeat * (repeatCnt[k] - repeatCnt[start])
                remainCnt = repeatCnt[start + (n1 - start) % interval]
                return (patternCnt + remainCnt) // n2
            nextIndex[k] = j
        return repeatCnt[n1] // n2


if __name__ == '__main__':
    s1 = input()
    n1 = int(input())
    s2 = input()
    n2 = int(input())
    solution = Solution()
    print(solution.getMaxRepetitions(s1, n1, s2, n2))
