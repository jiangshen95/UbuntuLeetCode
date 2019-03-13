class Solution:
    def minMoves2(self, nums) -> int:
        def findKth(start, end, k):
            i, j = start, end
            v = nums[(i + j) // 2]
            while i <= j:
                while nums[i] < v:
                    i += 1
                while nums[j] > v:
                    j -= 1
                if i >= j:
                    break
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
            if i - start + 1 == k and i == j:
                return nums[i]
            elif i - start + 1 > k:
                return findKth(start, i - 1, k)
            else:
                return findKth(j + 1, end, k - (j - start + 1))

        n = len(nums)
        target = findKth(0, n - 1, n // 2 + 1)
        return sum(abs(num - target) for num in nums)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.minMoves2(nums))
