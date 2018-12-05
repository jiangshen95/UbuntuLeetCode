class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = b = c = float('-inf')
        for num in nums:
            if num == a or num == b or num <= c:
                continue
            c = num
            if c > b:
                b, c = c, b
            if b > a:
                a, b = b, a
        return c if c > float('-inf') else a


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.thirdMax(nums))
