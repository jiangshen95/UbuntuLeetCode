class Solution:
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        cur = 1
        k -= 1
        while k > 0:
            step, first, last = 0, cur, cur + 1
            while first <= n:
                step += min(last, n + 1) - first
                first *= 10
                last *= 10
            if k >= step:
                k -= step
                cur += 1
            else:
                k -= 1
                cur *= 10
        return cur


if __name__ == '__main__':
    n = int(input())
    k = int(input())
    solution = Solution()
    print(solution.findKthNumber(n, k))
