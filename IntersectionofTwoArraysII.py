class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        m = {}
        for num in nums1:
            if num in m:
                m[num] += 1
            else:
                m[num] = 1
        result = []
        for num in nums2:
            if num in m and m[num] > 0:
                result.append(num)
                m[num] -= 1
        return result


if __name__ == '__main__':
    nums1 = [int(num) for num in input().split()]
    nums2 = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.intersection(nums1, nums2))
