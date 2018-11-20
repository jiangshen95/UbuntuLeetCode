class Solution:
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        def canCross(cur, k):
            if cur == stones[-1]:
                return True
            if (cur, k) in memo:
                return False

            for i in range(cur + k + 1, cur + k - 2, -1):
                if i > cur and i in stones and canCross(i, i - cur):
                    return True
            memo.add((cur, k))
            return False

        if len(stones) > 4:
            for i in range(4, len(stones)):
                if stones[i] > stones[i - 1] * 2:
                    return False
        memo = set()
        return canCross(0, 0)


if __name__ == '__main__':
    stones = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.canCross(stones))
