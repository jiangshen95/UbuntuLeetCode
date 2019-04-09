class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9
        for z in range(2, 2 * 9 * (10 ** n) - 1):
            left = 10 ** n - z
            right = int(str(left)[::-1])
            if z ** 2 - 4 * right < 0:
                continue
            x = 1 / 2 * (z + (z ** 2 - 4 * right) ** 0.5)
            y = 1 / 2 * (z - (z ** 2 - 4 * right) ** 0.5)
            if x.is_integer() or y.is_integer():
                return (10 ** n * left + right) % 1337
            # if (z ** 2 - 4 * right) ** 0.5 == int((z ** 2 - 4 * right) ** 0.5):
            #     return (10 ** n * left + right) % 1337


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.largestPalindrome(n))
