class Solution:
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if not envelopes:
            return 0
        n = len(envelopes)

        envelopes.sort()

        dp = [1] * n
        max_en = 1
        for i in range(1, n):
            for j in range(i):
                if envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
            max_en = max(max_en, dp[i])
        return max_en


if __name__ == '__main__':
    n = int(input())
    envelopes = []
    for i in range(n):
        envelopes.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.maxEnvelopes(envelopes))
