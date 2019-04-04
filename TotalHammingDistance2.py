class Solution:
    def totalHammingDistance(self, nums) -> int:
        return sum(b.count('0') * b.count('1') for b in zip(*map('{:032b}'.format, nums)))


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.totalHammingDistance(nums))
