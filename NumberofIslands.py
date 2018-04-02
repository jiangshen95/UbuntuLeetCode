class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def searchIsland(grid, i, j):
            if i<0 or i>=len(grid) or j<0 or j>=len(grid[0]) or grid[i][j] == '0':
                return
            grid[i][j] = '0'
            searchIsland(grid, i-1, j)
            searchIsland(grid, i+1, j)
            searchIsland(grid, i, j-1)
            searchIsland(grid, i, j+1)
        if len(grid) == 0:
            return 0
        number = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    number += 1
                    searchIsland(grid, i, j)
        return number
        
if __name__ == "__main__":
    m = int(raw_input())
    grid = []
    for i in range(m):
        grid.append(list(raw_input()))
    #print(grid)
    solution = Solution()
    print(solution.numIslands(grid))
