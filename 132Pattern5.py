class Solution:
    def find132pattern(self, nums) -> bool:
        n = len(nums)
        mn = nums.copy()
        for i in range(1, n, 1):
            mn[i] = min(mn[i - 1], mn[i])
        top = n
        for i in range(n - 1, -1, -1):
            if nums[i] <= mn[i]:
                continue
            while top < n and mn[i] >= mn[top]:
                top += 1
            if top < n and nums[i] > mn[top]:
                return True
            top -= 1
            mn[top] = nums[i]
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.find132pattern(nums))
