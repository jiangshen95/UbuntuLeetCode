class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        r = []
        i = 0
        while i < len(nums):
            begin = i
            while i + 1 < len(nums) and nums[i+1] == nums[i] + 1:
                i += 1
            if(i != begin):
                r.append([nums[begin], nums[i]])
            else:
                r.append([nums[i]])
            i += 1
        return ['->'.join(map(str, n)) for n in r]

if __name__ == '__main__':
    nums = list(input())
    solution = Solution()
    print(solution.summaryRanges(nums))
