class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        r1 = m-1
        r2 = n-1
        r = m+n-1
        while r1>=0 and r2>=0:
            if nums1[r1]>nums2[r2]:
                nums1[r] = nums1[r1]
                r -= 1
                r1 -= 1
            else:
                nums1[r] = nums2[r2]
                r -= 1
                r2 -= 1
        while r2>=0:
            nums1[r] = nums2[r2]
            r -= 1
            r2 -= 1
            
if __name__=='__main__':
    nums1 = list(input())
    nums2 = list(input())
    m = len(nums1)
    n = len(nums2)
    nums1+=[0 for i in range(n)]
    solution = Solution()
    solution.merge(nums1, m, nums2, n)
    print(nums1)
