class Solution:
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        def canCross(index, k):
            if index == len(stones) - 1:
                return True
            if (index, k) in memo:
                return False

            for i in range(index + 1, len(stones)):
                if stones[index] + k - 1 <= stones[i] <= stones[index] + k + 1:
                    if canCross(i, stones[i] - stones[index]):
                        return True
            memo.add((index, k))
            return False

        memo = set()
        return canCross(0, 0)


if __name__ == '__main__':
    stones = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.canCross(stones))
