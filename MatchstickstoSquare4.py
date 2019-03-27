class Solution:
    def makesquare(self, nums) -> bool:
        def dfs(mask, total, target):
            if (mask, total) in visited:
                return visited[mask, total]
            if mask == 0:
                return total == target
            if total == target:
                return dfs(mask, 0, target)

            for i in range(len(nums)):
                if mask & (1 << i):
                    if total + nums[i] <= target and dfs(mask ^ (1 << i), total + nums[i], target):
                        visited[mask, total] = True
                        return True
            visited[mask, total] = False
            return False

        if len(nums) <= 3:
            return False
        total = sum(nums)
        if total % 4 != 0:
            return False
        target = total // 4
        visited = {}
        return dfs((1 << len(nums)) - 1, 0, target)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.makesquare(nums))
