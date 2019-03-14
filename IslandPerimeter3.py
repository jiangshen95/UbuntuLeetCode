class Solution:
    def islandPerimeter(self, grid) -> int:
        def land_around(x, y):
            return (x > 0 and grid[x - 1][y]) + (x < len(grid) - 1 and grid[x + 1][y]) + \
                   (y > 0 and grid[x][y - 1]) + (y < len(grid[0]) - 1 and grid[x][y + 1])
        return sum(4 - land_around(i, j) for i in range(len(grid)) for j in range(len(grid[i])) if
                   grid[i][j])


if __name__ == '__main__':
    m = int(input())
    grid = []
    for i in range(m):
        grid.append([int(num) for num in input().split()])
    solution = Solution()
    print(solution.islandPerimeter(grid))
