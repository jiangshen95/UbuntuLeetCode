import random, bisect


class Solution:

    def __init__(self, rects: list):
        self.rects = rects

    def pick(self) -> list:
        sumArea = 0
        select = []
        for x1, y1, x2, y2 in self.rects:
            area = (x2 - x1 + 1) * (y2 - y1 + 1)
            sumArea += area
            if random.randint(1, sumArea) <= area:
                select = [x1, y1, x2, y2]
        return [random.randint(select[0], select[2]), random.randint(select[1], select[3])]


if __name__ == '__main__':
    n = int(input())
    rects = []
    for i in range(n):
        rects.append([int(num) for num in input().split()])

    solution = Solution(rects)
    print(solution.pick())
