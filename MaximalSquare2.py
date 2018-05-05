# Brute Force
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
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    squre = 1
                    flag = True
                    while i + squre < m and j + squre < n and flag:
                        for k in range(j, j + squre + 1):
                            if matrix[i + squre][k] == '0':
                                flag = False
                                break
                        for k in range(i, i + squre):
                            if matrix[k][j + squre] == '0':
                                flag = False
                                break
                        if flag:
                            squre += 1
                    result = max(result, squre * squre)
        return result
        
if __name__ == '__main__':
    m = int(raw_input())
    matrix = []
    for i in range(m):
        raw = raw_input()
        matrix.append(list(raw))
    solution = Solution()
    print(solution.maximalSquare(matrix))
