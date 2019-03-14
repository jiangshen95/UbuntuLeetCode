class Solution:
    def islandPerimeter(self, grid) -> int:
        return sum(sum(map(lambda x, y: x != y, [0] + row, row + [0]))
                   for row in grid + list(map(list, zip(*grid))))


if __name__ == '__main__':
    m = int(input())
    grid = []
    for i in range(m):
        grid.append([int(num) for num in input().split()])
    solution = Solution()
    print(solution.islandPerimeter(grid))
