class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zero = 0
        one = 0
        two = 0
        for i in range(len(nums)):
            if nums[i]==0:
                nums[two]=2
                nums[one]=1
                nums[zero]=0
                two+=1
                one+=1
                zero+=1
            elif nums[i]==1:
                nums[two]=2
                nums[one]=1
                two+=1
                one+=1
            elif nums[i]==2:
                nums[two]=2
                two+=1

if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    solution.sortColors(nums)
    print(nums)
