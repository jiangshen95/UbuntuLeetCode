class Solution:
    def minMoves(self, nums) -> int:
        min_num = min(nums)
        count = 0
        for num in nums:
            count += num - min_num
        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.minMoves(nums))
