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
            l, r = 0, len(dp) - 1
            t = envelopes[i][1]
            while l <= r:
                mid = l + (r - l) // 2
                if dp[mid] < t:
                    l = mid + 1
                elif dp[mid] >= t:
                    r = mid - 1
            if l == len(dp):
                dp.append(t)
            else:
                dp[l] = t
        return len(dp)


if __name__ == '__main__':
    n = int(input())
    envelopes = []
    for i in range(n):
        envelopes.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.maxEnvelopes(envelopes))
