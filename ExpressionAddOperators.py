class Solution:
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        def dfs(num, diff, curNum, out):
            if len(num) == 0 and curNum == target:
                result.append(out)
            for i in range(0, len(num)):
                cur = num[0: i + 1]
                if len(cur) > 1 and cur[0] == '0':
                    continue
                next = num[i + 1:]
                if len(out) > 0:
                    dfs(next, int(cur), curNum + int(cur), out + '+' + cur)
                    dfs(next, -int(cur), curNum - int(cur), out + '-' + cur)
                    dfs(next, diff * int(cur), curNum - diff + diff * int(cur), out + '*' + cur)
                else:
                    dfs(next, int(cur), int(cur), cur)
        result = []
        dfs(num, 0, 0, '')
        return result


if __name__ == '__main__':
    num = input()
    target = int(input())
    solution = Solution()
    print(solution.addOperators(num, target))
