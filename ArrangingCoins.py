class Solution:
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 1, n
        while l <= r:
            mid = l + (r - l) // 2
            if mid * (mid + 1) <= 2 * n:
                l = mid + 1
            else:
                r = mid - 1
        return l - 1


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.arrangeCoins(n))
