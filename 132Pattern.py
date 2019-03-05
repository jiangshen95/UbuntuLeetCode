class Solution:
    def find132pattern(self, nums) -> bool:
        stack = []
        third = -float('inf')
        for num in nums[::-1]:
            if num < third:
                return True
            while stack and stack[-1] < num:
                third = stack.pop()
            stack.append(num)
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.find132pattern(nums))
