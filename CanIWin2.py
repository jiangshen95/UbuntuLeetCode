class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        def canIWin(nums, total):
            if str(nums) in m:
                return m[str(nums)]
            for i in range(len(nums)):
                if nums[i] >= total or not canIWin(nums[: i] + nums[i + 1:], total - nums[i]):
                    m[str(nums)] = True
                    return True
            m[str(nums)] = False
            return False
        if maxChoosableInteger >= desiredTotal:
            return True
        if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
            return False

        m = {}
        return canIWin(list(range(maxChoosableInteger, 0, -1)), desiredTotal)


if __name__ == '__main__':
    maxChoosableInteger = int(input())
    desiredTotal = int(input())
    solution = Solution()
    print(solution.canIWin(maxChoosableInteger, desiredTotal))
