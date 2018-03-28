class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        start = 0
        k %= n
        while k > 0:
            for i in range(k):
                nums[start+i], nums[n - k + i + start] = nums[n - k + i + start], nums[start+i]
            n -= k
            start += k
            k %= n

if __name__ == '__main__':
    nums = list(input())
    k = int(raw_input())
    solution = Solution()
    solution.rotate(nums, k)
    print(nums)
