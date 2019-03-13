class Solution:
    def minMoves2(self, nums) -> int:
        nums.sort()
        i, j = 0, len(nums) - 1
        result = 0
        while i < j:
            result += nums[j] - nums[i]
            i += 1
            j -= 1
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.minMoves2(nums))
