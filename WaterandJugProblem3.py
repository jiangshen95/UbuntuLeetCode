class Solution:
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if z > x + y:
            return False
        if x > y:
            x, y = y, x

        queue = [(0, 0)]
        visited = set((0, 0))
        while queue:
            a, b = queue.pop(0)

            if a + b == z:
                return True

            states = set()
            states.add((a, 0))
            states.add((0, b))
            states.add((a, y))
            states.add((x, b))
            states.add((min(x, a + b), 0 if a + b < x else b - (x - a)))
            states.add((0 if a + b < y else a - (y - b), min(y, a + b)))

            for s in states:
                if s not in visited:
                    queue.append(s)
                    visited.add(s)
        return False


if __name__ == '__main__':
    x, y, z = (int(num) for num in input().split())
    solution = Solution()
    print(solution.canMeasureWater(x, y, z))
