class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def mergesort(nums):
            if len(nums) > 1:
                mid = len(nums) // 2
                left, right = mergesort(nums[: mid]), mergesort(nums[mid:])
                for i in range(len(nums) - 1, -1, -1):
                    if not right or left and left[-1][1] > right[-1][1]:
                        counts[left[-1][0]] += len(right)
                        nums[i] = left.pop()
                    else:
                        nums[i] = right.pop()
            return nums

        n = len(nums)
        counts = [0] * n
        enu = [enu for enu in enumerate(nums)]
        mergesort(enu)
        return counts


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.countSmaller(nums))
