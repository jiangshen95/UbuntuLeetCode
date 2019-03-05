class Solution:
    # Time Limit Exceeded
    def find132pattern(self, nums) -> bool:
        n = len(nums)
        mn = float('inf')
        for j in range(n):
            mn = min(mn, nums[j])
            if nums[j] == mn:
                continue
            for k in range(n - 1, j, -1):
                if mn < nums[k] < nums[j]:
                    return True
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.find132pattern(nums))
