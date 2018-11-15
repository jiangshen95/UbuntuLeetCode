class Solution:
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        num = list(num)
        for _ in range(k):
            for i in range(len(num)):
                if (i < len(num) - 1 and num[i] > num[i + 1]) or i == len(num) - 1:
                    num.pop(i)
                    break
        return ''.join(num).lstrip('0') or '0'


if __name__ == '__main__':
    num = input()
    k = int(input())
    solution = Solution()
    print(solution.removeKdigits(num, k))
