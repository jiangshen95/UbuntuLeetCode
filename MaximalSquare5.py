# DP
class Solution:
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        
        result = 0
        dp = [0] * (m + 1)
        pre = 0
        
        for j in range(n):
            for i in range(1, m + 1):
                t = dp[i]
                if matrix[i - 1][j] == '0':
                    dp[i] = 0
                else:
                    dp[i] = min(dp[i], dp[i-1], pre) + 1
                    result = max(result, dp[i])
                pre = t
                
        return result * result
        
if __name__ == '__main__':
    m = int(raw_input())
    matrix = []
    for i in range(m):
        raw = raw_input()
        matrix.append(list(raw))
    solution = Solution()
    print(solution.maximalSquare(matrix))

