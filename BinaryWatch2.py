class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def getTimes(count, n, time):
            nums = [0]
            for i in range(count):
                temp = []
                for nu in nums:
                    for j in range(n):
                        t = (nu << (j + 1)) + (1 << j)
                        if t < time:
                            temp.append(t)
                nums = temp
            return nums

        result = []
        for i in range(4):
            if 0 <= num - i < 6:
                hours = getTimes(i, 4, 12)
                minutes = getTimes(num - i, 6, 60)
                for h in hours:
                    for m in minutes:
                        result.append('%d:%02d' % (h, m))
        return result


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.readBinaryWatch(num))
