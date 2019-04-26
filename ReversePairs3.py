class Solution:
    def reversePairs(self, nums: list) -> int:

        def mergeSort(left, right):
            if left >= right:
                return 0
            mid = (left + right) // 2
            count = mergeSort(left, mid) + mergeSort(mid + 1, right)
            print(count)
            i, t, j = left, left, mid + 1
            cache = []
            while j <= right:
                while i <= mid and nums[i] <= nums[j] * 2:
                    i += 1
                count += mid - i + 1
                while t <= mid and nums[t] <= nums[j]:
                    cache.append(nums[t])
                    t += 1
                cache.append(nums[j])
                j += 1
            while t <= mid:
                cache.append(nums[t])
                t += 1
            for i in range(left, right + 1):
                nums[i] = cache[i - left]
            print(left, right)
            print(nums)
            return count

        return mergeSort(0, len(nums) - 1)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.reversePairs(nums))
