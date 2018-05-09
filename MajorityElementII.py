class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        competitor1, competitor2 = 0, 1
        count1, count2 = 0, 0
        for n in nums:
            if n == competitor1:
                count1 += 1
            elif n == competitor2:
                count2 += 1
            elif count1 == 0:
                competitor1 = n
                count1 = 1
            elif count2 == 0:
                competitor2 = n
                count2 = 1
            else:
                count1, count2 = count1 - 1, count2 - 1
                
        return [n for n in (competitor1, competitor2) if nums.count(n) > len(nums) // 3]
        
if __name__ == '__main__':
    nums = list(input())
    solution = Solution()
    print(solution.majorityElement(nums))
