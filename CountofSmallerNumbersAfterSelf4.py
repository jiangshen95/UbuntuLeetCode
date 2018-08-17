class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def getCount(i):
            count = 0
            while i > 0:
                count += tree[i]
                i -= (i & -i)
            return count

        def update(i):
            while i < len(tree):
                tree[i] += 1
                i += (i & -i)

        n = len(nums)
        counts = [0] * n
        min_num = 2147483647
        max_num = -2147483648
        for num in nums:
            min_num = min(min_num, num)
        nums2 = [0] * n
        for i in range(n):
            nums2[i] = nums[i] - min_num + 1
            max_num = max(max_num, nums2[i])
        tree = [0] * (max_num + 1)
        for i in range(n - 1, -1, -1):
            counts[i] = getCount(nums2[i] - 1)
            update(nums2[i])
        return counts


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.countSmaller(nums))
