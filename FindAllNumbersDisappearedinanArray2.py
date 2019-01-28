class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        i = 0
        while i < len(nums):
            while nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                # nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
                t = nums[i]
                nums[i] = nums[t - 1]
                nums[t - 1] = t
            i += 1
        result = []
        for i in range(len(nums)):
            if nums[i] != i + 1:
                result.append(i + 1)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findDisappearedNumbers(nums))
