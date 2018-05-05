# 累加数组
# Time Limit Exceeded
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
        sumof = [[0] * n for _ in range(m)] 
        
        for i in range(m):
            for j in range(n):
                temp = int(matrix[i][j])
                if j > 0:
                    temp += sumof[i][j-1]
                if i > 0:
                    temp += sumof[i-1][j]
                if i > 0 and j > 0:
                    temp -= sumof[i-1][j-1]
                sumof[i][j] = temp
                
                for k in range(1, min(i, j) + 2):
                    d = sumof[i][j]
                    if i - k >= 0:
                        d -= sumof[i - k][j]
                    if j - k >= 0:
                        d -= sumof[i][j - k]
                    if i - k >= 0 and j - k >= 0:
                        d += sumof[i - k][j - k]
                    if d == k * k:
                        result = max(result, d)
                
        return result
        
if __name__ == '__main__':
    m = int(raw_input())
    matrix = []
    for i in range(m):
        raw = raw_input()
        matrix.append(list(raw))
    solution = Solution()
    print(solution.maximalSquare(matrix))
