class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def getTime(bytes):
            hour = 0
            for i in range(4):
                if bytes[i]:
                    hour |= (1 << i)
            minute = 0
            for i in range(4, 10):
                if bytes[i]:
                    minute |= (1 << (i - 4))
            if hour <12 and minute < 60:
                return '%d:%02d' % (hour, minute)
            else:
                return None

        def helper(count, i):
            if count == 0:
                t = getTime(bytes)
                if t:
                    result.append(t)
                return
            if i >= 10:
                return
            bytes[i] = 0
            helper(count, i + 1)
            bytes[i] = 1
            helper(count - 1, i + 1)
            bytes[i] = 0

        bytes = [0] * 10
        result = []
        helper(num, 0)
        return result


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.readBinaryWatch(num))
