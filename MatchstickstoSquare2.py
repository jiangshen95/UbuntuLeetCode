class Solution:
    def makesquare(self, nums) -> bool:
        def makeSide(pos, total, count, target):
            if total == target:
                if count == 4:
                    return True
                if makeSide(0, 0, count + 1, target):
                    return True
                return False

            for i in range(pos, len(nums), 1):
                if not visited[i] and total + nums[i] <= target:
                    visited[i] = True
                    if makeSide(i + 1, total + nums[i], count, target):
                        return True
                    visited[i] = False
            return False

        if len(nums) <= 3:
            return False
        total = sum(nums)
        if total % 4 != 0:
            return False
        target = total // 4
        visited = [False] * (len(nums))
        return makeSide(0, 0, 1, target)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.makesquare(nums))
