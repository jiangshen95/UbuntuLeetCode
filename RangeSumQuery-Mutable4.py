class SegmentTreeNode:
    def __init__(self, i, j):
        self.i = i
        self.j = j
        self.left = None
        self.right = None
        self.sum = 0

class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        if not nums:
            return
        self.root = self.build(nums, 0, len(nums) - 1)

    def build(self, nums, begin, end):
        if begin > end:
            return None
        root = SegmentTreeNode(begin, end)
        if begin == end:
            root.sum = nums[begin]
        else:
            mid = begin + (end - begin) // 2
            root.left = self.build(nums, begin, mid)
            root.right = self.build(nums, mid + 1, end)
            root.sum = root.left.sum + root.right.sum
        return root

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        def update(root, i, val):
            if root.i == root.j:
                root.sum = val
            else:
                mid = root.i + (root.j - root.i) // 2
                if i > mid:
                    update(root.right, i, val)
                else:
                    update(root.left, i, val)
                root.sum = root.left.sum + root.right.sum
        update(self.root, i, val)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        def sumRange(root, i, j):
            if root.i == i and root.j == j:
                return root.sum
            mid = root.i + (root.j - root.i) // 2
            if i > mid:
                return sumRange(root.right, i, j)
            elif j <= mid:
                return sumRange(root.left, i, j)
            else:
                return sumRange(root.left, i, mid) + sumRange(root.right, mid + 1, j)
        return sumRange(self.root, i, j)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    arr = NumArray(nums)
    print(arr.sumRange(0, 2))
    arr.update(1, 2)
    print(arr.sumRange(0, 2))
