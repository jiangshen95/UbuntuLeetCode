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
                allsums = [0]
                for x in range(m):
                    sums[x] += matrix[x][j]
                    allsums.append(allsums[-1] + sums[x])
                max_sub = max(max_sub, self.mergesort(allsums, 0, m, k))
                if max_sub == k:
                    return k

        return max_sub

    def mergesort(self, allsums, left, right, k):
        if left >= right:
            return -2147483648
        mid = left + (right - left) // 2
        max_sum = self.mergesort(allsums, left, mid, k)
        if max_sum == k:
            return k
        max_sum = max(max_sum, self.mergesort(allsums, mid + 1, right, k))
        if max_sum == k:
            return k

        i, j, p = left, mid + 1, mid + 1
        cache = [0] * (right - left + 1)
        index = 0
        while i <= mid:
            while j <= right and allsums[j] - allsums[i] <= k:
                j += 1
            if j > mid + 1:
                max_sum = max(max_sum, allsums[j - 1] - allsums[i])
                if max_sum == k:
                    return k
            while p <= right and allsums[p] < allsums[i]:
                cache[index] = allsums[p]
                index += 1
                p += 1
            cache[index] = allsums[i]
            index += 1
            i += 1
        for i in range(index):
            allsums[left + i] = cache[i]
        return max_sum


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])
    k = int(input())

    solution = Solution()
    print(solution.maxSumSubmatrix(matrix, k))
