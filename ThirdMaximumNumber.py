class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = b = c = float('-inf')
        for num in nums:
            if num == a or num == b or num == c:
                continue
            if num > a:
                c = b
                b = a
                a = num
            elif num > b:
                c = b
                b = num
            elif num > c:
                c = num
        return c if c > float('-inf') else a


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.thirdMax(nums))
