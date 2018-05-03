from heapq import *

class Solution:
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        heights = []
        for building in buildings:
            heights.append([building[0], -building[2]])
            heights.append([building[1], building[2]])
        heights.sort()
        print(heights)
        result = []
        heap = [0]
        cur = 0
        pre = 0
        for height in heights:
            if height[1] < 0:
                heappush(heap, -height[1])
            else:
                heap.remove(height[1])
            print(heap)
            cur = nlargest(1, heap)[0]
            if cur != pre:
                result.append([height[0], cur])
                pre = cur
        return result
        
if __name__ == '__main__':
    n = int(raw_input())
    buildings = []
    for i in range(n):
        building = list(input())
        buildings.append(building)
    solution = Solution()
    print(solution.getSkyline(buildings))
