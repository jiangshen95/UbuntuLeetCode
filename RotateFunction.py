class Solution:
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        s = 0
        f = 0
        for i, num in enumerate(A):
            s += num
            f += i * num
        res = f
        for i in range(n - 1, 0, -1):
            f = f + s - n * A[i]
            res = max(res, f)
        return res


if __name__ == '__main__':
    A = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.maxRotateFunction(A))
