class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        diff = 0
        for num in nums:
            diff ^= num
        diff &= -diff  # 补码的方式相与，可以获得最右侧的一位1

        result = [0, 0]
        for num in nums:
            if diff & num:
                result[0] ^= num
            else:
                result[1] ^= num
        return result

if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.singleNumber(nums))
