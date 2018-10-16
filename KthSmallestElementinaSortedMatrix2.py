import heapq


class Solution:
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        n = len(matrix)
        q = []
        for i in range(n):
            heapq.heappush(q, (matrix[0][i], 0, i))
        for _ in range(k):
            v, i, j = heapq.heappop(q)
            if i + 1 < n:
                heapq.heappush(q, (matrix[i + 1][j], i + 1, j))
        return v


if __name__ == '__main__':
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append([int(num) for num in input().split()])
    k = int(input())
    solution = Solution()
    print(solution.kthSmallest(matrix, k))
