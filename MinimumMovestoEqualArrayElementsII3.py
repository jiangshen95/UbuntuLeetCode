class Solution:
    def minMoves2(self, nums) -> int:
        nums.sort()
        n = len(nums)
        s = sum(nums)
        curSum = 0
        result = float('inf')
        for i in range(n):
            k = nums[i]
            curSum += k
            result = min(result, 2 * (i + 1) * k - n * k + s - 2 * curSum)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.minMoves2(nums))
