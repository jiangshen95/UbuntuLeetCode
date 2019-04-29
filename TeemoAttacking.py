class Solution:
    def findPoisonedDuration(self, timeSeries: list, duration: int) -> int:
        if not timeSeries:
            return 0
        cur = timeSeries[0]
        result = duration
        for i in range(1, len(timeSeries)):
            result += duration if cur + duration <= timeSeries[i] else timeSeries[i] - cur
            cur = timeSeries[i]
        return result


if __name__ == '__main__':
    timeSeries = [int(num) for num in input().split()]
    duration = int(input())
    solution = Solution()
    print(solution.findPoisonedDuration(timeSeries, duration))
