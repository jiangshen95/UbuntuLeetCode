class Solution:
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        miss = 1
        i = 0
        count = 0
        while miss <= n:
            if i < len(nums) and nums[i] <= miss:
                miss += nums[i]
                i += 1
            else:
                miss += miss
                count += 1

        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    n = int(input())
    solution = Solution()
    print(solution.minPatches(nums, n))
