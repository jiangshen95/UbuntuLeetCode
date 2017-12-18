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
        
        height = [0]*n
        left = [0]*n
        right = [0]*n
        ans = 0
        
        for i in range(m):
            curr_left = 0
            curr_right = n
            for j in range(n):
                height[j] = height[j]+1 if matrix[i][j]=='1' else 0
            
            for j in range(n):
                if matrix[i][j]=='1':
                    left[j] = max(left[j], curr_left)
                else:
                    left[j] = 0
                    curr_left = j+1
                    
            for j in range(n-1, -1, -1):
                if matrix[i][j]=='1':
                    right[j] = min(right[j], curr_right)
                else:
                    right[j] = n
                    curr_right = j
                    
            for j in range(n):
                if (right[j]-left[j])*height[j]>ans:
                    ans = (right[j]-left[j])*height[j]
                    
        return ans

if __name__=='__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append(list(raw_input()))
    print(matrix)
    
    solution = Solution()
    print(solution.maximalRectangle(matrix))
