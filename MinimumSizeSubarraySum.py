class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        r = 0
        minSub = -1
        sumof = 0
        while r < len(nums):
            sumof += nums[r]
            r += 1
            while sumof >= s:
                if minSub == -1 or r - l < minSub:
                    minSub = r - l
                sumof -= nums[l]
                l += 1
        return 0 if minSub == -1 else minSub
        
if __name__ == '__main__':
    s = int(raw_input())
    nums = list(input())
    solution = Solution()
    print(solution.minSubArrayLen(s, nums))
