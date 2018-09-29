class Solution:
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if z == 0 or z == x + y:
            return True
        if z > x + y:
            return False

        if x > y:
            x, y = y, x

        v = 0
        while True:
            if v < x:
                v += y
            else:
                v -= x
            if v == z:
                return True
            if v == 0:
                return False

        return False


if __name__ == '__main__':
    x, y, z = (int(num) for num in input().split())
    solution = Solution()
    print(solution.canMeasureWater(x, y, z))
