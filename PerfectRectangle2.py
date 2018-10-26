class Solution:
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        st = []
        lx, ly, rx, ry = 2147483647, 2147483647, 0, 0
        area = 0
        for rect in rectangles:
            lx = min(lx, rect[0])
            ly = min(ly, rect[1])
            rx = max(rx, rect[2])
            ry = max(ry, rect[3])
            area += (rect[2] - rect[0]) * (rect[3] - rect[1])

            if (rect[0], rect[1]) not in st:
                st.append((rect[0], rect[1]))
            else:
                st.remove((rect[0], rect[1]))
            if (rect[0], rect[3]) not in st:
                st.append((rect[0], rect[3]))
            else:
                st.remove((rect[0], rect[3]))
            if (rect[2], rect[3]) not in st:
                st.append((rect[2], rect[3]))
            else:
                st.remove((rect[2], rect[3]))
            if (rect[2], rect[1]) not in st:
                st.append((rect[2], rect[1]))
            else:
                st.remove((rect[2], rect[1]))
        if (lx, ly) not in st or (lx, ry) not in st or (rx, ly) not in st or (rx, ry) not in st:
            return False
        return len(st) == 4 and area == (rx - lx) * (ry - ly)


if __name__ == '__main__':
    n = int(input())
    rectangles = []
    for i in range(n):
        rectangles.append([int(num) for num in input().split()])
    solution = Solution()
    print(solution.isRectangleCover(rectangles))
