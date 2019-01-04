class Solution:
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in range(31, -1, -1):
            prefix = {num >> i << i for num in nums}
            t = result | (1 << i)
            for p in prefix:
                if (t ^ p) in prefix:
                    result = t
                    break
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findMaximumXOR(nums))
