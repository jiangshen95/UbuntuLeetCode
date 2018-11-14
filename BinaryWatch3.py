class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def getTimes(count, index, n, sum, times):
            if count == 0:
                if (n == 4 and sum < 12) or (n == 6 and sum < 60):
                    times.append(sum)
                return
            for i in range(index, n):
                getTimes(count - 1, i + 1, n, sum + (1 << i), times)

        result = []
        for i in range(4):
            if 0 <= num - i < 6:
                hours = []
                getTimes(i, 0, 4, 0, hours)
                minutes = []
                getTimes(num - i, 0, 6, 0, minutes)
                for h in hours:
                    for m in minutes:
                        result.append('%d:%02d' % (h, m))
        return result


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.readBinaryWatch(num))
