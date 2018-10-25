class Solution:
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        head = 1
        end = n
        step = 1
        left = True
        while head < end:
            if left:
                head += step
                if n % 2 == 1:
                    end -= step
            else:
                end -= step
                if n % 2 == 1:
                    head += step
            step *= 2
            left = not left
            n //= 2
        return head


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.lastRemaining(n))
