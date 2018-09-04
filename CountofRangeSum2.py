class Solution:
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        def findIndex(sums, val):
            l, r = 0, len(sums) - 1
            while l <= r:
                mid = l + (r - l) //2
                if sums[mid] > val:
                    r = mid - 1
                else:
                    l = mid + 1
            return l

        def countRangeSum(begin, end):
            if begin == end:
                return 1 if lower <= nums[begin] <= upper else 0
            if begin > end:
                return 0
            mid = begin + (end - begin) // 2
            s = 0
            sums = []
            for i in range(mid + 1, end + 1):
                s += nums[i]
                sums.append(s)
            sums.sort()

            s = 0
            count = 0
            for i in range(mid, begin - 1, -1):
                s += nums[i]
                count += findIndex(sums, upper - s + 0.5) - findIndex(sums, lower - s - 0.5)

            return count + countRangeSum(begin, mid) + countRangeSum(mid + 1, end)

        return countRangeSum(0, len(nums) - 1)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    lower = int(input())
    upper = int(input())
    solution = Solution()
    print(solution.countRangeSum(nums, lower, upper))
