import heapq


class Solution:
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        def binary_search(nums, l, r, target):
            while l <= r:
                mid = l + (r - l) // 2
                if nums[mid] <= target:
                    l = mid + 1
                else:
                    r = mid - 1
            return l

        n = len(matrix)
        low, high = matrix[0][0], matrix[-1][-1]
        while low < high:
            mid = low + (high - low) // 2
            count = 0
            for i in range(n):
                count += binary_search(matrix[i], 0, n - 1, mid)
            if count < k:
                low = mid + 1
            else:
                high = mid
        return low


if __name__ == '__main__':
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append([int(num) for num in input().split()])
    k = int(input())
    solution = Solution()
    print(solution.kthSmallest(matrix, k))
