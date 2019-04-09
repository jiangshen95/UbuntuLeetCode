class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9
        upper = 10 ** n - 1
        lower = upper // 10
        for i in range(upper, lower, -1):
            p, t = i, i
            while t > 0:
                p = p * 10 + t % 10
                t //= 10
            for j in range(upper, lower, -1):
                if j * j < p:
                    break
                if p % j == 0:
                    return p % 1337
        return 0


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.largestPalindrome(n))
