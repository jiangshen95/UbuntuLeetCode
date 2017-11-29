class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zero = 0
        one = 0
        for i in range(len(nums)):
            v = nums[i]
            nums[i] = 2
            if v==1:
                nums[one]=1
                one+=1
            elif v==0:
                nums[one]=1
                one+=1
                nums[zero]=0
                zero+=1
                
            '''
            if v<2:
                nums[one]=1
                one+=1
            if v==0:
                nums[zero]=0
                zero+=1
            '''

if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    solution.sortColors(nums)
    print(nums)
