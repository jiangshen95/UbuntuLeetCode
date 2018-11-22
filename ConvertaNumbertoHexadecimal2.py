class Solution:
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        if num < 0:
            num += 2 ** 32
        hex_num = '0123456789abcdef'
        count = 0
        hex = ''
        while num > 0:
            hex = hex_num[num % 16] + hex
            num //= 16
        return hex


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.toHex(num))
