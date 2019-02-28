class Solution:
    def minMoves(self, nums) -> int:
        return sum(nums) - len(nums) * min(nums)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.minMoves(nums))
