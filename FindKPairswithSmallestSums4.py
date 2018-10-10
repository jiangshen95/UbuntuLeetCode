import heapq


class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        queue = []
        if not nums1 or not nums2:
            return []
        for i in range(len(nums1)):
            heapq.heappush(queue, (nums1[i] + nums2[0], i, 0))
        result = []
        while len(result) < k and queue:
            s, i, j = heapq.heappop(queue)
            result.append([nums1[i], nums2[j]])
            if j + 1 < len(nums2):
                heapq.heappush(queue, (nums1[i] + nums2[j + 1], i, j + 1))
        return result


if __name__ == '__main__':
    nums1 = [int(num) for num in input().split()]
    nums2 = [int(num) for num in input().split()]
    k = int(input())
    solution = Solution()
    print(solution.kSmallestPairs(nums1, nums2, k))
