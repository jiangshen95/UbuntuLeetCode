class Solution:
    def findSubsequences(self, nums: list) -> list:
        result, cur = [], [[]]
        m = {}
        for i in range(len(nums)):
            start = m.get(nums[i], 0)
            n = len(cur)
            m[nums[i]] = n
            for j in range(start, n, 1):
                if not cur[j] or cur[j][-1] <= nums[i]:
                    cur.append(cur[j].copy())
                    cur[-1].append(nums[i])
                    if len(cur[-1]) >= 2:
                        result.append(cur[-1])
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.findSubsequences(nums))
