class Solution:
    def circularArrayLoop(self, nums) -> bool:
        n = len(nums)
        for i in range(n):
            if nums[i] == 0:
                continue
            k = i
            next = ((i + nums[i]) % n + n) % n
            is_loop1 = False
            visited = [False] * n
            while nums[k] != 0 and nums[k] * nums[next] >= 0:
                if k == next:
                    is_loop1 = True
                visited[k] = True
                nums[k] = 0
                k = next
                next = ((next + nums[next]) % n + n) % n
            if not is_loop1 and visited[k] and nums[k] == 0:
                return True
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.circularArrayLoop(nums))
