class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        i1, i2 = len(num1) - 1, len(num2) - 1
        result = ""
        carry = 0
        while i1 >= 0 or i2 >= 0 or carry > 0:
            if i1 >= 0:
                carry += ord(num1[i1]) - ord('0')
            if i2 >= 0:
                carry += ord(num2[i2]) - ord('0')
            result = str(carry % 10) + result
            carry //= 10
            i1 -= 1
            i2 -= 1
        return result


if __name__ == '__main__':
    num1 = input()
    num2 = input()
    solution = Solution()
    print(solution.addStrings(num1, num2))
