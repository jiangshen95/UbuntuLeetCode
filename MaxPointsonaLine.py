class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
        
class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        def gcd(a, b):
            return a if b==0 else gcd(b, a%b)
        result = 0
        for i in range(len(points)):
            duplicate = 1
            hash_map = {}
            for j in range(i+1, len(points)):
                if points[i].x == points[j].x and points[i].y == points[j].y:
                    duplicate += 1
                    continue
                dx = points[j].x - points[i].x
                dy = points[j].y - points[i].y
                d = gcd(dx, dy)
                if (dx//d, dy//d) in hash_map:
                    hash_map[(dx//d, dy//d)] += 1
                else:
                    hash_map[(dx//d, dy//d)] = 1
            result = max(result, duplicate)
            for key, value in hash_map.items():
                result = max(result, value + duplicate)
        return result
        
if __name__=='__main__':
    nums = list(input())
    
    points = []
    for i in range(0, len(nums), 2):
        points.append(Point(nums[i], nums[i+1]))
    
    solution = Solution()
    print(solution.maxPoints(points))
