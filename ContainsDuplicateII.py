class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dic = {}
        for i in range(len(nums)):
            if nums[i] in dic:
                if i - dic[nums[i]] <= k:
                    return True
            dic[nums[i]] = i
        return False
        
if __name__ == '__main__':
    nums = list(input())
    k = int(raw_input())
    solution = Solution()
    print(solution.containsNearbyDuplicate(nums, k))
