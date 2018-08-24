class Solution:
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        def compare(nums1, nums2):
            for i in range(min(len(nums1), len(nums2))):
                if nums1[i] < nums2[i]:
                    return False
                elif nums1[i] > nums2[i]:
                    return True
            return len(nums1) > len(nums2)

        def getMax(nums, k):
            n = len(nums)
            drop = n - k
            res = []
            for num in nums:
                while drop and res and res[-1] < num:
                    res.pop()
                    drop -= 1
                res.append(num)
            return res[: k]

        def merge(nums1, nums2):
            nums = []
            while nums1 or nums2:
                nums.append(nums1.pop(0) if compare(nums1, nums2) else nums2.pop(0))
            return nums

        m = len(nums1)
        n = len(nums2)
        result = []
        for i in range(max(0, k - n), min(k, m) + 1):
            temp = merge(getMax(nums1, i), getMax(nums2, k - i))
            if compare(temp, result):
                result = temp
        return result


if __name__ == '__main__':
    nums1 = [int(num) for num in input().split()]
    nums2 = [int(num) for num in input().split()]
    k = int(input())
    solution = Solution()
    print(solution.maxNumber(nums1, nums2, k))
