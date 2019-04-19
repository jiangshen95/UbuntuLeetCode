class Solution:
    def findSubsequences(self, nums: list) -> list:
        subs = {()}
        for num in nums:
            subs |= {sub + (num, ) for sub in subs if not sub or sub[-1] <= num}
        return [list(sub) for sub in subs if len(sub) >= 2]


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findSubsequences(nums))
