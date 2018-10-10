class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        return sorted([[a, b] for a in nums1 for b in nums2], key=sum)[:k]


if __name__ == '__main__':
    nums1 = [int(num) for num in input().split()]
    nums2 = [int(num) for num in input().split()]
    k = int(input())
    solution = Solution()
    print(solution.kSmallestPairs(nums1, nums2, k))
