class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        v = []
        import heapq
        for num in nums:
            if num not in v:
                heapq.heappush(v, num)
            if len(v) > 3:
                heapq.heappop(v)
        return heapq.heappop(v) if len(v) == 3 else max(v)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.thirdMax(nums))
