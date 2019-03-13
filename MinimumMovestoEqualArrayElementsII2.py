class Solution:
    def minMoves2(self, nums) -> int:
        nums.sort()
        target = nums[len(nums) // 2]
        result = 0
        for num in nums:
            result += abs(num - target)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.minMoves2(nums))
