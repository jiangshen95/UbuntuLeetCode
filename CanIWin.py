class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        def canIWin(total, used):
            if used in m:
                return m[used]
            for i in range(maxChoosableInteger, 0, -1):
                cur = 1 << (i - 1)
                if not (used & cur):
                    if i >= total or not canIWin(total - i, used | cur):
                        m[used] = True
                        return True
            m[used] = False
            return False
        if maxChoosableInteger >= desiredTotal:
            return True
        if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
            return False
        m = {}
        return canIWin(desiredTotal, 0)


if __name__ == '__main__':
    maxChoosableInteger = int(input())
    desiredTotal = int(input())
    solution = Solution()
    print(solution.canIWin(maxChoosableInteger, desiredTotal))
