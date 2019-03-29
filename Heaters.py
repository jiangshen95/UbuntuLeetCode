class Solution:
    def findRadius(self, houses, heaters) -> int:
        houses.sort()
        heaters.sort()
        result = heaters[0] - houses[0]
        index = 0
        for i in range(1, len(heaters), 1):
            r = 0
            for j in range(index, len(houses), 1):
                if houses[j] < heaters[i - 1]:
                    continue
                if heaters[i - 1] <= houses[j] <= heaters[i]:
                    r = max(r, min(houses[j] - heaters[i - 1], heaters[i] - houses[j]))
                else:
                    break
            index = j
            result = max(result, r)
        result = max(result, houses[-1] - heaters[-1])
        return result


if __name__ == '__main__':
    houses = [int(num) for num in input().split()]
    heaters = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findRadius(houses, heaters))
