class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def mergesort(begin, end):
            mid = begin + (end - begin) // 2
            left_index = begin
            right_index = mid + 1
            sort_index = 0
            right_count = 0
            new_indexes = [0] * (end - begin + 1)

            while left_index <= mid and right_index <= end:
                if nums[indexes[left_index]] > nums[indexes[right_index]]:
                    new_indexes[sort_index] = indexes[right_index]
                    right_count += 1
                    sort_index += 1
                    right_index += 1
                else:
                    new_indexes[sort_index] = indexes[left_index]
                    counts[indexes[left_index]] += right_count
                    left_index += 1
                    sort_index += 1
            while left_index <= mid:
                new_indexes[sort_index] = indexes[left_index]
                counts[indexes[left_index]] += right_count
                sort_index += 1
                left_index += 1
            while right_index <= end:
                new_indexes[sort_index] = indexes[right_index]
                sort_index += 1
                right_index += 1
            for i in range(begin, end + 1):
                indexes[i] = new_indexes[i - begin]

        def merge(begin, end):
            if begin >= end:
                return

            mid = begin + (end - begin) // 2
            merge(begin, mid)
            merge(mid + 1, end)

            mergesort(begin, end)

        n = len(nums)
        indexes = [_ for _ in range(n)]
        counts = [0] * n
        merge(0, n - 1)
        return counts


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.countSmaller(nums))
