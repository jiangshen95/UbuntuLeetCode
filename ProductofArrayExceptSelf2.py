class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        multi1 = [1] * n
        multi2 = [1] * n
        for i in range(1, n):
            multi1[i] = multi1[i - 1] * nums[i - 1]
            multi2[n - i - 1] = multi2[n - i] * nums[n - i]
        for i in range(n):
            multi2[i] *= multi1[i]

        return multi2

if __name__ == '__main__':
    str_in = input()
    nums = [int(num) for num in str_in.split()]
    solution = Solution()
    result = solution.productExceptSelf(nums)
    print(result)
