class Solution:
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        def isAdditive(num1, num2, index):
            s = num1 + num2
            i = index
            while i < len(num):
                num1 = num2
                num2 = s
                s = str(s)
                if num[i: i + len(s)] != s:
                    return False
                i += len(s)
                s = num1 + num2
            return True
        for i in range(len(num) - 2):
            if i > 0 and num[0] == '0':
                break
            for j in range(i + 1, len(num) - 1):
                if j > i + 1 and num[i + 1] == '0':
                    break
                if isAdditive(int(num[:i + 1]), int(num[i + 1: j + 1]), j + 1):
                    return True
        return False


if __name__ == '__main__':
    num = input()
    solution = Solution()
    print(solution.isAdditiveNumber(num))