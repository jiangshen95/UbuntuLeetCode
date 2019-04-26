class Solution:
    def __init__(self):
        self.count = 0

    def reversePairs(self, nums: list) -> int:
        def mergesort(lst):
            if len(lst) <= 1:
                return lst
            else:
                return merge(mergesort(lst[: len(lst) // 2]), mergesort(lst[len(lst) // 2:]))

        def merge(left, right):
            l, r = 0, 0
            while l < len(left):
                while r < len(right) and left[l] > right[r] * 2:
                    r += 1
                self.count += r
                l += 1
            return sorted(left + right)
        mergesort(nums)
        return self.count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.reversePairs(nums))
