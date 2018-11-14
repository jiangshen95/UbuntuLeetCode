class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        # result = []
        # for h in range(12):
        #     for m in range(60):
        #         if (bin(h) + bin(m)).count('1') == num:
        #             result.append(str(h) + ":" + "0" * (m < 10) + str(m))
        # return result
        return ['%d:%02d' % (h, m) for h in range(12) for m in range(60) if (bin(h) + bin(m)).count('1')
                == num]


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.readBinaryWatch(num))
