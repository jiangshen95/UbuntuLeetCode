import heapq


class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        if not nums1 or not nums2:
            return []
        result = []
        n1, n2 = len(nums1), len(nums2)
        index = [0] * n1
        for i in range(k):
            min_sum = 2147483647
            min_index = -1
            for j in range(n1):
                if index[j] < n2 and nums1[j] + nums2[index[j]] < min_sum:
                    min_sum = nums1[j] + nums2[index[j]]
                    min_index = j
            if min_index == -1:
                break
            result.append([nums1[min_index], nums2[index[min_index]]])
            index[min_index] += 1
        return result


if __name__ == '__main__':
    nums1 = [int(num) for num in input().split()]
    nums2 = [int(num) for num in input().split()]
    k = int(input())
    solution = Solution()
    print(solution.kSmallestPairs(nums1, nums2, k))
