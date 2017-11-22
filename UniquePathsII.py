class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        
        temp = [0 for i in range(m)]
        temp[0] = 1
        for j in range(n):
            for i in range(m):
                if j==0 and i==0:
                    if obstacleGrid[i][j]:
                        temp[i] = 0
                    continue
                if obstacleGrid[i][j]:
                    temp[i] = 0
                else:
                    temp[i] = (temp[i] if j-1>=0 else 0) + (temp[i-1] if i-1>=0 else 0)
        return temp[m-1]
        
if __name__=='__main__':
    m = int(input())
    obstacleGrid = []
    for i in range(m):
        row = list(input())
        obstacleGrid.append(row)
        
    solution = Solution()
    print(solution.uniquePathsWithObstacles(obstacleGrid))
