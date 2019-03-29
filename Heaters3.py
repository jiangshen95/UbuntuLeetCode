class Solution:
    def findRadius(self, houses, heaters) -> int:
        houses.sort()
        heaters.sort()
        result = 0
        index = 0
        for house in houses:
            left = index
            right = len(heaters) - 1
            while left <= right:
                mid = (left + right) // 2
                if heaters[mid] < house:
                    left = mid + 1
                else:
                    right = mid - 1
            index = left
            dist1 = float('inf') if left == len(heaters) else heaters[left] - house
            dist2 = float('inf') if left == 0 else house - heaters[left - 1]
            result = max(result, min(dist1, dist2))
        return result


if __name__ == '__main__':
    houses = [int(num) for num in input().split()]
    heaters = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findRadius(houses, heaters))
