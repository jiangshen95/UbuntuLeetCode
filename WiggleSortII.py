class Solution:
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        temp = sorted(nums)
        n = len(nums)
        r1 = (n + 1) // 2 - 1
        r2 = n - 1
        for i in range(n):
            if i & 1:
                nums[i] = temp[r2]
                r2 -= 1
            else:
                nums[i] = temp[r1]
                r1 -= 1


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    solution.wiggleSort(nums)
    print(nums)
