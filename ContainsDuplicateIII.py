class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if k < 1 or t < 0:
            return False
        dic = {}
        for i in range(len(nums)):
            if i > k:
                del dic[nums[i - k - 1] // (t + 1)]
            bucket = nums[i] // (t + 1)
            if bucket in dic or \
            (bucket - 1 in dic and nums[i] - dic[bucket - 1] <= t) or \
            (bucket + 1 in dic and dic[bucket + 1] - nums[i] <= t):
                return True
            dic[bucket] = nums[i]
        return False
        
if __name__ == '__main__':
    nums = list(input())
    k = int(raw_input())
    t = int(raw_input())
    solution = Solution()
    print(solution.containsNearbyAlmostDuplicate(nums, k, t))
