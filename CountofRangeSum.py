class Solution:
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        def countAndMergeSort(begin, end):
            if begin >= end:
                return 0
            mid = begin + (end - begin) // 2
            count = countAndMergeSort(begin, mid) + countAndMergeSort(mid + 1, end)

            temp = [0] * (end - begin + 1)
            r = 0
            j, k, l = mid + 1, mid + 1, mid + 1
            for i in range(begin, mid + 1):
                while j <= end and sums[j] - sums[i] < lower:
                    j += 1
                while k <= end and sums[k] - sums[i] <= upper:
                    k += 1
                count += k - j
                while l <= end and sums[l] < sums[i]:
                    temp[r] = sums[l]
                    l += 1
                    r += 1
                temp[r] = sums[i]
                r += 1
            for i in range(begin, l):
                sums[i] = temp[i - begin]
            return count

        sums = [0]
        for num in nums:
            sums.append(sums[-1] + num)
        return countAndMergeSort(0, len(sums) - 1)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    lower = int(input())
    upper = int(input())
    solution = Solution()
    print(solution.countRangeSum(nums, lower, upper))
