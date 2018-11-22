class Solution:
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        hex_num = '0123456789abcdef'
        count = 0
        hex = ''
        while num != 0 and count < 8:
            hex = hex_num[num & 15] + hex
            num >>= 4
            count += 1
        return hex


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.toHex(num))
