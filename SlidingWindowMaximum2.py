class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if len(nums) == 0 or k <= 0:
            return []
        n = len(nums)
        left_max = [0] * n
        right_max = [0] * n

        for i in range(n):
            if i % k == 0:
                left_max[i] = nums[i]
            else:
                left_max[i] = max(nums[i], left_max[i - 1])
            if (n - i) % k == 0 or n - i - 1 == n - 1:
                right_max[n - i - 1] = nums[n - i - 1]
            else:
                right_max[n - i - 1] = max(nums[n - i - 1], right_max[n - i])

        result = []
        for i in range(n - k + 1):
            result.append(max(right_max[i], left_max[i + k - 1]))
        return result

if __name__ == '__main__':
    str_in = input()
    nums = [int(num) for num in str_in.split()]
    k = int(input())
    solution = Solution()
    print(solution.maxSlidingWindow(nums, k))
