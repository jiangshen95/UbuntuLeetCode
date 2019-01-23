class Solution:
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def getCount(n, prefix):
            step = 1
            count = 0
            while prefix <= n:
                count += step
                prefix *= 10
                step *= 10
            if n < (prefix // 10 + step // 10 - 1):
                count -= step // 10 - (n - prefix // 10 + 1)
            return count

        def helper(n, k, prefix):
            for i in range(1 if prefix == 0 else 0, 10):
                num = getCount(n, prefix * 10 + i)
                if k <= num:
                    if k == 1:
                        return prefix * 10 + i
                    else:
                        return helper(n, k - 1, prefix * 10 + i)
                else:
                    k -= num
            return 0
        return helper(n, k, 0)


if __name__ == '__main__':
    n = int(input())
    k = int(input())
    solution = Solution()
    print(solution.findKthNumber(n, k))
