class Solution:
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if not envelopes:
            return 0
        n = len(envelopes)

        envelopes.sort(key=lambda x: (x[0], -x[1]))

        dp = []
        for i in range(n):
            l, r = 0, len(dp)
            t = envelopes[i][1]
            while l < r:
                mid = l + (r - l) // 2
                if dp[mid] < t:
                    l = mid + 1
                else:
                    r = mid
            if r == len(dp):
                dp.append(t)
            else:
                dp[r] = t
        return len(dp)


if __name__ == '__main__':
    n = int(input())
    envelopes = []
    for i in range(n):
        envelopes.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.maxEnvelopes(envelopes))
