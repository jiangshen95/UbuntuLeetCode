import heapq


class Solution:
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        def search_less_equal(target):
            i, j = n - 1, 0
            count = 0
            while i >= 0 and j < n:
                if target >= matrix[i][j]:
                    count += i + 1
                    j += 1
                else:
                    i -= 1
            return count

        n = len(matrix)
        low, high = matrix[0][0], matrix[-1][-1]
        while low < high:
            mid = low + (high - low) // 2
            count = search_less_equal(mid)
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
