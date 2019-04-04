class Solution:
    def totalHammingDistance(self, nums) -> int:
        count = 0
        for i in range(32):
            cnt = 0
            for num in nums:
                cnt += (num >> i) & 1
            count += cnt * (len(nums) - cnt)
        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.totalHammingDistance(nums))
