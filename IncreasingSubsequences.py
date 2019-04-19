class Solution:
    def findSubsequences(self, nums: list) -> list:
        def findSubsequence(pos):
            if len(sequence) >= 2:
                result.append(sequence.copy())
            for i in range(pos, len(nums), 1):
                if nums[i] in nums[pos: i]:
                    continue
                if not sequence or sequence[-1] <= nums[i]:
                    sequence.append(nums[i])
                    findSubsequence(i + 1)
                    sequence.pop(-1)

        result = []
        sequence = []
        findSubsequence(0)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findSubsequences(nums))
