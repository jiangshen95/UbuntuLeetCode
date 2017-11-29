class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        col0 = False
        for i in range(m):
            if matrix[i][0]==0:
                col0 = True
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(m-1, -1 ,-1):
            for j in range(n-1, 0, -1):
                if matrix[i][0]==0 or matrix[0][j]==0:
                    matrix[i][j]=0
            if col0:
                matrix[i][0] = 0
                
if __name__=='__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        raw = list(input())
        matrix.append(raw)
    print(matrix)
    solution = Solution()
    solution.setZeroes(matrix)
    print(matrix)
