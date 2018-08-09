class Solution:
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        def isAdditive(num1, num2, index):
            if index >= len(num):
                return True
            s = num1 + num2
            if num[index: index + len(str(s))] == str(s):
                return isAdditive(num2, s, index + len(str(s)))
            return False
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