class Solution:
    def constructRectangle(self, area: int) -> list:
        import math
        w = int(math.sqrt(area))
        while w > 0:
            if area % w == 0:
                return [area // w, w]
            w -= 1
        return []


if __name__ == '__main__':
    area = int(input())
    solution = Solution()
    print(solution.constructRectangle(area))
