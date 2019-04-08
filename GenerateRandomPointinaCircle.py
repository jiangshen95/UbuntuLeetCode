class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self):
        import random
        while True:
            x = random.uniform(self.x_center - self.radius, self.x_center + self.radius)
            y = random.uniform(self.y_center - self.radius, self.y_center + self.radius)
            if (x - self.x_center) ** 2 + (y - self.y_center) ** 2 <= self.radius ** 2:
                return [x, y]


if __name__ == '__main__':
    radius = float(input())
    x_center = float(input())
    y_center = float(input())
    solution = Solution(radius, x_center, y_center)
    print(solution.randPoint())
