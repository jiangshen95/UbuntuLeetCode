class Solution:
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def selectKth(nums, k):
            l = 0
            r = len(nums) - 1
            while l < r:
                v = nums[l]
                i = l + 1
                for j in range(l + 1, r + 1):
                    if nums[j] < v:
                        nums[j], nums[i] = nums[i], nums[j]
                        i += 1
                i -= 1
                nums[i], nums[l] = nums[l], nums[i]
                if i < k:
                    l = i + 1
                elif i > k:
                    r = i - 1
                else:
                    break
            return nums[k]
        n = len(nums)
        # mid = selectKth(nums, n // 2)
        mid = sorted(nums)[n // 2]
        print(nums)
        A = lambda i: (1 + 2 * i) % (n | 1)
        i, j, k = 0, 0, n - 1
        while j <= k:
            if nums[A(j)] > mid:
                nums[A(i)], nums[A(j)] = nums[A(j)], nums[A(i)]
                i += 1
                j += 1
            elif nums[A(j)] < mid:
                nums[A(j)], nums[A(k)] = nums[A(k)], nums[A(j)]
                k -= 1
            else:
                j += 1


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    solution.wiggleSort(nums)
    print(nums)
