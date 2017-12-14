class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        l = 0
        r = len(nums)-1
        while l<=r:
            mid = (l+r)//2
            if nums[mid]==target:
                return True
            elif nums[mid]==nums[l] and nums[mid]==nums[r]:
                l+=1
                r-=1
            elif nums[mid]>=nums[l]:
                if nums[mid]>target and nums[l]<=target:
                    r = mid-1
                else:
                    l = mid+1
            else:
                if nums[mid]<target and nums[r]>=target:
                    l = mid+1
                else:
                    r = mid-1
        return False
        
if __name__=="__main__":
    nums=list(input())
    target=input()
    solution=Solution()
    print(solution.search(nums, target))
