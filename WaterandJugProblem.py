class Solution:
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        def gcd(a, b):
            while b > 0:
                c = a % b
                a = b
                b = c
            return a

        if z == 0:
            return True
        if z > x + y:
            return False
        return z % gcd(x, y) == 0


if __name__ == '__main__':
    x, y, z = (int(num) for num in input().split())
    solution = Solution()
    print(solution.canMeasureWater(x, y, z))
