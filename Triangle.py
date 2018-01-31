class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle)==0:
            return 0
        dp = triangle[-1]
        
        for i in range(len(triangle)-2, -1, -1):
            for j in range(i+1):
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j]
        return dp[0]
        
if __name__=='__main__':
    n = int(raw_input())
    triangle = []
    for i in range(n):
        row = list(input())
        triangle.append(row)
    solution = Solution()
    print(solution.minimumTotal(triangle))
