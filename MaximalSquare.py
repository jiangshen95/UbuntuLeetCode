# Brute Force
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
        
        for i in range(m):
            v = [0] * n
            for j in range(i, m):
                for k in range(n):
                    v[k] += int(matrix[j][k])
                count = 0
                squre = 0
                for x in v:
                    if x == j - i + 1:
                        count += 1;
                    else:
                        count = 0
                    if count == j - i + 1:
                        squre = x * x
                        break
                result = max(result, squre)
        return result
        
if __name__ == '__main__':
    m = int(raw_input())
    matrix = []
    for i in range(m):
        raw = raw_input()
        matrix.append(list(raw))
    solution = Solution()
    print(solution.maximalSquare(matrix))
