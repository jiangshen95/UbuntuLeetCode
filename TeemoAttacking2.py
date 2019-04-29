class Solution:
    def findPoisonedDuration(self, timeSeries: list, duration: int) -> int:
        if not timeSeries:
            return 0
        result = duration
        for i in range(1, len(timeSeries)):
            result += duration - max(0, timeSeries[i - 1] + duration - timeSeries[i])
        return result


if __name__ == '__main__':
    timeSeries = [int(num) for num in input().split()]
    duration = int(input())
    solution = Solution()
    print(solution.findPoisonedDuration(timeSeries, duration))
