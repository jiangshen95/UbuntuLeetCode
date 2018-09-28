import bisect


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

        max_sub = -2147483648
        for i in range(n):
            sums = [0] * m
            for j in range(i, n):
                s = [0]
                curSum = 0
                curMax = -2147483648
                for x in range(m):
                    sums[x] += matrix[x][j]
                    curSum += sums[x]
                    index = bisect.bisect_left(s, curSum - k)
                    if index != len(s):
                        curMax = max(curMax, curSum - s[index])
                    bisect.insort(s, curSum)
                max_sub = max(max_sub, curMax)

        return max_sub


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])
    k = int(input())

    solution = Solution()
    print(solution.maxSumSubmatrix(matrix, k))
