class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = 1
        max_num = int(pow(10, n))
        used = 0
        for i in range(1, 10):
            used |= (1 << i)
            s += self.search(i, max_num, used)
            used = 0
        return s

    def search(self, pre, max_num, used):
        res = 0
        if pre < max_num:
            res += 1
        else:
            return res

        for i in range(10):
            if not (used & (1 << i)):
                used |= (1 << i)
                cur = 10 * pre + i
                res += self.search(cur, max_num, used)
                used &= ~(1 << i)
        return res


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.countNumbersWithUniqueDigits(n))
