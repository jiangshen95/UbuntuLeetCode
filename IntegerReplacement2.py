class Solution:
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        step = 0
        while n != 1:
            if (n & 1) == 0:
                n >>= 1
            elif n != 3 and (n + 1) % 4 == 0:
                n += 1
            else:
                n -= 1
            step += 1
        return step


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.integerReplacement(n))
