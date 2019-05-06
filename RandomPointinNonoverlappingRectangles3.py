import random, bisect


class Solution:

    def __init__(self, rects: list):
        self.rects = rects
        self.areas = []
        sumArea = 0
        for rect in rects:
            area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1)
            sumArea += area
            self.areas.append(sumArea)

    def pick(self) -> list:
        left, right = 0, len(self.areas) - 1
        target = random.randint(1, self.areas[-1])
        while left <= right:
            mid = (left + right) // 2
            if self.areas[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        x1, y1, x2, y2 = self.rects[left]
        return [random.randint(x1, x2), random.randint(y1, y2)]


if __name__ == '__main__':
    n = int(input())
    rects = []
    for i in range(n):
        rects.append([int(num) for num in input().split()])

    solution = Solution(rects)
    print(solution.pick())
