class Solution:
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        def count_points(coor, mask):
            if coor not in m:
                m[coor] = 0
            if m[coor] & mask != 0:
                return False
            m[coor] |= mask
            return True

        m = {}
        lx, ly, rx, ry = 2147483647, 2147483647, 0, 0
        area = 0
        for rect in rectangles:
            lx = min(lx, rect[0])
            ly = min(ly, rect[1])
            rx = max(rx, rect[2])
            ry = max(ry, rect[3])
            area += (rect[2] - rect[0]) * (rect[3] - rect[1])
            if not count_points((rect[0], rect[1]), 1):
                return False
            if not count_points((rect[0], rect[3]), 2):
                return False
            if not count_points((rect[2], rect[3]), 4):
                return False
            if not count_points((rect[2], rect[1]), 8):
                return False
        cnt = 0
        for v in m.values():
            if v == 1 or v == 2 or v == 4 or v == 8:
                cnt += 1
        return cnt == 4 and area == (rx - lx) * (ry - ly)


if __name__ == '__main__':
    n = int(input())
    rectangles = []
    for i in range(n):
        rectangles.append([int(num) for num in input().split()])
    solution = Solution()
    print(solution.isRectangleCover(rectangles))
