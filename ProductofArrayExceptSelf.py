class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        result = [1] * n
        for i in range(1, n):
            result[i] = result[i - 1] * nums[i - 1]
        temp = 1
        for i in range(n - 2, -1, -1):
            temp *= nums[i + 1]
            result[i] *= temp
        return result

if __name__ == '__main__':
    str_in = input()
    nums = [int(num) for num in str_in.split()]
    solution = Solution()
    result = solution.productExceptSelf(nums)
    print(result)
