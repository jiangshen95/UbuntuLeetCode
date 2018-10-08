class Solution:
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        S = {-1: set()}
        for x in sorted(nums):
            S[x] = max((S[d] for d in S if x % d == 0), key=len) | {x}
        return list(max(S.values(), key=len))


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.largestDivisibleSubset(nums))
