class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # quick sort
        def partition(left, right):
            v = nums[left]
            while left < right:
                while left < right and nums[right] <= v:
                    right -= 1
                nums[left] = nums[right]
                while left < right and nums[left] >= v:
                    left += 1
                nums[right] = nums[left]
            nums[left] = v
            return left
        i = partition(0, len(nums) - 1)
        while i != k-1:
            if i > k-1:
                i = partition(0, i - 1)
            else:
                i = partition(i + 1, len(nums) - 1)
        return nums[i]
        
if __name__ == '__main__':
    nums = list(input())
    k = int(raw_input())
    solution = Solution()
    print(solution.findKthLargest(nums, k))
