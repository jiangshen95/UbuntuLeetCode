class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if i==0 and j==0:
                    continue
                if i==0:
                    grid[i][j] = grid[i][j-1] + grid[i][j]
                elif j==0:
                    grid[i][j] = grid[i-1][j] + grid[i][j]
                else:
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j]
        return grid[len(grid)-1][len(grid[0])-1]

if __name__=='__main__':
    m = int(input())
    grid = []
    for i in range(m):
        row = list(input())
        grid.append(row)
        
    solution = Solution()
    print(solution.minPathSum(grid))
