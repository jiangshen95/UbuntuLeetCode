class Solution:
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        nums = [1]
        i2, i3, i5 = 0, 0, 0
        while len(nums) < n:
            m = min(nums[i2] * 2, nums[i3] * 3, nums[i5] * 5)
            if m == nums[i2] * 2:
                i2 += 1
            if m == nums[i3] * 3:
                i3 += 1
            if m == nums[i5] * 5:
                i5 += 1
            nums.append(m)
        return nums[-1]

if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.nthUglyNumber(n))
