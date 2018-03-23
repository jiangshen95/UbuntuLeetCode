class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = {}
        for num in nums:
            if num in dic:
                dic[num] += 1
            else:
                dic[num] = 1
            if dic[num] > len(nums)//2:
                return num
                
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.majorityElement(nums))
