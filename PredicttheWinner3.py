class Solution:
    def PredictTheWinner(self, nums: list) -> bool:
        def canWin(start, end, sum1, sum2, time):
            if start > end:
                if time % 2 == 0:
                    return sum1 >= sum2
                else:
                    return sum2 > sum1
            if time % 2 == 0:
                return not canWin(start + 1, end, sum1 + nums[start], sum2, time + 1) or not canWin(start, end - 1,
                                                                                                    sum1 + nums[end],
                                                                                                    sum2, time + 1)
            else:
                return not canWin(start + 1, end, sum1, sum2 + nums[start], time + 1) or not canWin(start, end - 1, sum1,
                                                                                                    sum2 + nums[end],
                                                                                                    time + 1)
        return canWin(0, len(nums) - 1, 0, 0, 0)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.PredictTheWinner(nums))
