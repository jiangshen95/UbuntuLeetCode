import math


class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n = int(n)
        max_m = int(math.log(n + 1, 2))
        for m in range(max_m, 1, -1):
            left = int((n + 1) ** m ** -1)
            right = int(n ** (m - 1) ** -1) + 1
            while left < right:
                mid = left + (right - left) // 2
                s = (mid ** m - 1) // (mid - 1)
                if s == n:
                    return str(mid)
                elif s < n:
                    left = mid + 1
                else:
                    right = mid - 1
        return str(n - 1)


if __name__ == '__main__':
    n = input()
    solution = Solution()
    print(solution.smallestGoodBase(n))
