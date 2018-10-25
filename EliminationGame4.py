class Solution:
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        head = 1
        step = 1
        left = True
        while n > 1:
            if left or n % 2 == 1:
                head += step
            step *= 2
            left = not left
            n //= 2
        return head


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.lastRemaining(n))
