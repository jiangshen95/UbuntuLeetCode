class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self):
        import random, math
        theta = random.uniform(0, 2 * math.pi)
        l = math.sqrt(random.uniform(0, self.radius ** 2))
        return [l * math.cos(theta) + self.x_center, l * math.sin(theta) + self.y_center]


if __name__ == '__main__':
    radius = float(input())
    x_center = float(input())
    y_center = float(input())
    solution = Solution(radius, x_center, y_center)
    print(solution.randPoint())
