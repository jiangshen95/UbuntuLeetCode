class Solution:
    def find132pattern(self, nums) -> bool:
        stack = []
        for num in nums:
            if not stack or stack[-1][0] > num:
                stack.append([num, num])
            elif stack[-1][0] < num:
                last = stack.pop()
                if num < last[1]:
                    return True
                else:
                    last[1] = num
                    while stack and stack[-1][1] <= num:
                        stack.pop()
                    if stack and num > stack[-1][0]:
                        return True
                    stack.append(last)
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.find132pattern(nums))
