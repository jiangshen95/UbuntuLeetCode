class Solution:
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        def count_points(coor):
            if coor not in m:
                m[coor] = 0
            m[coor] += 1

        m = {}
        lx, ly, rx, ry = 2147483647, 2147483647, 0, 0
        area = 0
        for rect in rectangles:
            lx = min(lx, rect[0])
            ly = min(ly, rect[1])
            rx = max(rx, rect[2])
            ry = max(ry, rect[3])
            area += (rect[2] - rect[0]) * (rect[3] - rect[1])
            count_points((rect[0], rect[1]))
            count_points((rect[0], rect[3]))
            count_points((rect[2], rect[3]))
            count_points((rect[2], rect[1]))
        bond = [(lx, ly), (lx, ry), (rx, ly), (rx, ry)]
        for coor in bond:
            if coor not in m or m[coor] != 1:
                return False
        for key in m.keys():
            if m[key] % 2 != 0 and key not in bond:
                return False
        return area == (rx - lx) * (ry - ly)


if __name__ == '__main__':
    n = int(input())
    rectangles = []
    for i in range(n):
        rectangles.append([int(num) for num in input().split()])
    solution = Solution()
    print(solution.isRectangleCover(rectangles))
