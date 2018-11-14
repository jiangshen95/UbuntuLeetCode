class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def getTimes(count, index, hour, minute):
            if count == 0:
                result.append('%d:%02d' % (hour, minute))
                return
            for i in range(index, 10):
                if i < 4:
                    t = hour | (1 << i)
                    if t < 12:
                        getTimes(count - 1, i + 1, t, minute)
                else:
                    t = minute | (1 << (i - 4))
                    if t < 60:
                        getTimes(count - 1, i + 1, hour, t)

        result = []
        getTimes(num, 0, 0, 0)
        return result


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.readBinaryWatch(num))
