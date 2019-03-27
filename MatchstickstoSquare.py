class Solution:
    def makesquare(self, nums) -> bool:
        def makeSide(pos, target):
            if pos >= len(nums):
                return all(s == target for s in sums)
            state = tuple(sorted(sums))
            if state in visited:
                return False
            for i in range(4):
                if sums[i] + nums[pos] <= target:
                    sums[i] += nums[pos]
                    if makeSide(pos + 1, target):
                        return True
                    sums[i] -= nums[pos]
            visited.add(state)
            return False

        if len(nums) <= 3:
            return False
        total = sum(nums)
        if total % 4 != 0:
            return False
        target = total // 4
        sums = [0] * 4
        nums.sort(key=lambda x: -x)
        visited = set()
        return makeSide(0, target)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.makesquare(nums))
