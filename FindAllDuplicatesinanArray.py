class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        i = 0
        while i < len(nums):
            if nums[i] != i + 1:
                t = nums[i]
                if nums[t - 1] != t:
                    nums[i] = nums[t - 1]
                    nums[t - 1] = t
                    continue
            i += 1

        result = []
        for i in range(len(nums)):
            if nums[i] != i + 1:
                result.append(nums[i])
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findDuplicates(nums))
