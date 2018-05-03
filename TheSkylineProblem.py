from heapq import *

class Solution:
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        result = []
        i, n = 0, len(buildings)
        live = []
        while i < n or len(live) > 0:
            if len(live) == 0 or i < n and buildings[i][0] <= -live[0][1]:
                x = buildings[i][0]
                while i < n and buildings[i][0] == x:
                    heappush(live, (-buildings[i][2], -buildings[i][1]))
                    i += 1
            else:
                x = -live[0][1]
                while len(live) > 0 and -live[0][1] <= x:
                    heappop(live)
            h = len(live) and -live[0][0]
            if len(result) == 0 or h != result[-1][1]:
                result.append([x, h])
        return result
        
if __name__ == '__main__':
    n = int(raw_input())
    buildings = []
    for i in range(n):
        building = list(input())
        buildings.append(building)
    solution = Solution()
    print(solution.getSkyline(buildings))
