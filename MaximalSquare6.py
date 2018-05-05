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
        
        for j in range(n):
            for i in range(m):
                matrix[i][j] = int(matrix[i][j])
                if matrix[i][j] == 1 and i > 0 and j > 0:
                    matrix[i][j] = min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]) + 1
                result = max(result, matrix[i][j])
                
        return result * result
        
if __name__ == '__main__':
    m = int(raw_input())
    matrix = []
    for i in range(m):
        raw = raw_input()
        matrix.append(list(raw))
    solution = Solution()
    print(solution.maximalSquare(matrix))

