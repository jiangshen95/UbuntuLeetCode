class Solution:
    def circularArrayLoop(self, nums) -> bool:
        n = len(nums)
        for i in range(n):
            if type(nums[i]) != int:
                continue
            mark = str(i)
            direction = (nums[i] > 0)
            while type(nums[i]) == int and direction ^ (nums[i] < 0) and nums[i] % n != 0:
                val = nums[i]
                nums[i] = mark
                i = ((i + val) % n + n) % n
            if nums[i] == mark:
                return True

        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.circularArrayLoop(nums))
