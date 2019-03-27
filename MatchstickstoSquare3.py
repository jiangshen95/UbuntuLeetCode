class Solution:
    def makesquare(self, nums) -> bool:
        if len(nums) <= 3:
            return False
        total = sum(nums)
        if total % 4 != 0:
            return False
        target = total // 4
        n = len(nums)
        length = (1 << n) - 1

        masks = []
        validHalf = set()
        for i in range(1, length + 1, 1):
            curSum = 0
            for j in range(n):
                if (1 << j) & i:
                    curSum += nums[j]
            if curSum == target:
                for mask in masks:
                    if i & mask:
                        continue
                    half = i | mask
                    validHalf.add(half)
                    if length ^ half in validHalf:
                        return True
                masks.append(i)
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.makesquare(nums))
