class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        dp = [{} for _ in range(n)]
        result = 0
        for i in range(n):
            for j in range(i):
                diff = A[i] - A[j]
                dp[i][diff] = dp[i].get(diff, 0) + 1
                if diff in dp[j]:
                    dp[i][diff] += dp[j][diff]
                    result += dp[j][diff]
        return result


if __name__ == '__main__':
    A = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.numberOfArithmeticSlices(A))
