class Solution:
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nan = float('nan')
        # print(nan)
        diffs = [a - b for a, b in zip([nan] + nums, nums + [nan]) if a - b]
        return sum(not d * e >= 0 for d, e in zip(diffs, diffs[1:]))


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.wiggleMaxLength(nums))
