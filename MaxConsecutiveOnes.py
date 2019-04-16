class Solution:
    def findMaxConsecutiveOnes(self, nums: list) -> int:
        result, count = 0, 0
        for num in nums:
            count = count + 1 if num == 1 else 0
            print(count)
            result = max(result, count)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findMaxConsecutiveOnes(nums))
