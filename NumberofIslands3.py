class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def searchIsland(i, j):
            if 0<=i<len(grid) and 0<=j<len(grid[0]) and grid[i][j] == '1':
                grid[i][j] = '0'
                list(map(searchIsland, [i-1, i+1, i, i], [j, j, j-1, j+1])) # python3的改变的map的机制，延迟计算，使用iter，不使用就不会计算
                return 1
            return 0
        return sum(searchIsland(i, j) for i in range(len(grid)) for j in range(len(grid[i])))
        
if __name__ == "__main__":
    m = int(input())
    grid = []
    for i in range(m):
        grid.append(list(input()))
    #print(grid)
    solution = Solution()
    print(solution.numIslands(grid))
