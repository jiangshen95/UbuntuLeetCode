class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            a, b = rand7(), rand7()
            num = (a - 1) * 7 + b
            if num <= 40:
                return num % 10 + 1
            a = num - 40
            b = rand7()
            num = (a - 1) * 7 + b
            if num <= 60:
                return num % 10 + 1
            a = num - 60
            b = rand7()
            num = (a - 1) * 7 + b
            if num <= 20:
                return num % 10 + 1
