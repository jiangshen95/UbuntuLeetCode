class Solution:
    def islandPerimeter(self, grid) -> int:
        islands = 0
        neighbors = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]:
                    islands += 1
                    if i > 0 and grid[i - 1][j]:
                        neighbors += 1
                    if j > 0 and grid[i][j - 1]:
                        neighbors += 1
        return islands * 4 - neighbors * 2


if __name__ == '__main__':
    m = int(input())
    grid = []
    for i in range(m):
        grid.append([num for num in input().split()])
    solution = Solution()
    print(solution.islandPerimeter(grid))
