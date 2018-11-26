class Solution:
    # Time Limit Exceeded
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not heightMap:
            return 0
        m = len(heightMap)
        n = len(heightMap[0])
        if m < 3 or n < 3:
            return 0

        wetMap = [[0] * n for _ in range(m)]
        result = 0
        for i in range(1, m - 1):
            wetMap[i] = self.calculate(heightMap[i])

        for j in range(1, n - 1):
            col = []
            for i in range(m):
                col.append(heightMap[i][j])

            colRes = self.calculate(col)

            for i in range(m):
                wetMap[i][j] = max(wetMap[i][j], colRes[i])
                result += wetMap[i][j]

        # print(wetMap)
        spillWater = True
        dir = [[0, -1], [0, 1], [-1, 0], [1, 0]]
        while spillWater:
            spillWater = False
            for i in range(1, m - 1):
                for j in range(1, n - 1):
                    if wetMap[i][j] > 0:
                        for k in range(4):
                            x, y = i + dir[k][0], j + dir[k][1]
                            curHeight = wetMap[i][j] + heightMap[i][j]
                            neighborHeight = wetMap[x][y] + heightMap[x][y]
                            if curHeight > neighborHeight:
                                spilledWater = curHeight - max(heightMap[i][j], neighborHeight)
                                wetMap[i][j] = max(0, wetMap[i][j] - spilledWater)
                                result -= spilledWater
                                spillWater = True
        return result

    def calculate(self, height):
        n = len(height)
        result = [0] * n
        stack = []
        i = 0
        while i < n:
            if not stack or height[i] <= height[stack[-1]]:
                stack.append(i)
                i += 1
            else:
                bottom = stack.pop()
                if stack:
                    for j in range(stack[-1] + 1, i):
                        result[j] += min(height[stack[-1]], height[i]) - height[bottom]
        return result


if __name__ == '__main__':
    m = int(input())
    heightMap = []
    for i in range(m):
        heightMap.append([int(h) for h in input().split()])
    print(heightMap)
    solution = Solution()
    print(solution.trapRainWater(heightMap))
