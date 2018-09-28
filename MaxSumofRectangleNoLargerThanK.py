class Solution:
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        if not matrix:
            return 0
        m = len(matrix)
        n = len(matrix[0])
        if n == 0:
            return 0

        sum = [[0] * n for _ in range(m)]
        max_sub = -2147483648
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    sum[i][j] = matrix[i][j]
                elif i == 0:
                    sum[i][j] = sum[i][j - 1] + matrix[i][j]
                elif j == 0:
                    sum[i][j] = sum[i - 1][j] + matrix[i][j]
                else:
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + matrix[i][j] - sum[i - 1][j - 1]
                print(sum)
                for x in range(i + 1):
                    for y in range(j + 1):
                        if x == 0 and y == 0:
                            s = sum[i][j]
                        elif x == 0:
                            s = sum[i][j] - sum[i][y - 1]
                        elif y == 0:
                            s = sum[i][j] - sum[x - 1][j]
                        else:
                            s = sum[i][j] - sum[x - 1][j] - sum[i][y - 1] + sum[x - 1][y - 1]
                        print(s)
                        if s == k:
                            return k
                        if s <= k:
                            max_sub = max(max_sub, s)

        return max_sub


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])
    k = int(input())

    solution = Solution()
    print(solution.maxSumSubmatrix(matrix, k))
