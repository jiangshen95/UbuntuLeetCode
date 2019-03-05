class Solution:
    def find132pattern(self, nums) -> bool:
        i = 0
        n = len(nums)
        while i < n:
            while i < n - 1 and nums[i] >= nums[i + 1]:
                i += 1
            j = i + 1
            while j < n - 1 and nums[j] <= nums[j + 1]:
                j += 1
            for k in range(j + 1, n):
                if nums[i] < nums[k] < nums[j]:
                    return True
            i = j + 1
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.find132pattern(nums))
