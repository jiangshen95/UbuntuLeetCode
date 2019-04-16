class Solution:
    def findMaxConsecutiveOnes(self, nums: list) -> int:
        print(''.join(map(str, nums)).split('0'))
        return max(map(len, ''.join(map(str, nums)).split('0')))


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findMaxConsecutiveOnes(nums))
