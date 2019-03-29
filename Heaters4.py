class Solution:
    def findRadius(self, houses, heaters) -> int:
        heaters.sort()
        import bisect
        return max(min(abs(house - heater) for i in [bisect.bisect(heaters, house)]
                       for heater in heaters[i - (i > 0): i + 1])
                   for house in houses)


if __name__ == '__main__':
    houses = [int(num) for num in input().split()]
    heaters = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findRadius(houses, heaters))
