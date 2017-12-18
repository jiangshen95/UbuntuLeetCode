class Solution:
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if len(matrix)<=0:
            return 0
        m = len(matrix)
        n = len(matrix[0])
        
        height = [0]*(n+1)
        ans = 0
        
        for i in range(m):
            for j in range(n):
                height[j] = height[j]+1 if matrix[i][j]=='1' else 0
            stack = [-1]
            for j in range(n+1):
                while height[j]<height[stack[-1]]:
                    h = height[stack.pop()]
                    w = j-1-stack[-1]
                    ans = max(ans, h*w)
                stack.append(j)
        return ans

if __name__=='__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append(list(raw_input()))
    print(matrix)
    
    solution = Solution()
    print(solution.maximalRectangle(matrix))
