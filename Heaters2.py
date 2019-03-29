class Solution:
    def findRadius(self, houses, heaters) -> int:
        houses.sort()
        heaters.sort()
        result = 0
        index = 0
        for house in houses:
            while index < len(heaters) - 1 and abs(heaters[index + 1] - house) <= abs(house - heaters[index]):
                index += 1
            result = max(result, abs(heaters[index] - house))
        return result


if __name__ == '__main__':
    houses = [int(num) for num in input().split()]
    heaters = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findRadius(houses, heaters))
