class Solution:
    class BSTNode:
        def __init__(self, val):
            self.val = val
            self.count = 1
            self.left_count = 0
            self.left = None
            self.right = None

    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        def getBound(root, val, includeSelf):
            if not root:
                return 0
            elif root.val == val:
                return root.left_count + (root.count if includeSelf else 0)
            elif root.val > val:
                return getBound(root.left, val, includeSelf)
            else:
                return root.left_count + root.count + getBound(root.right, val, includeSelf)

        def insertNode(root, val):
            if root.val == val:
                root.count += 1
            elif root.val > val:
                root.left_count += 1
                if not root.left:
                    root.left = self.BSTNode(val)
                else:
                    insertNode(root.left, val)
            else:
                if not root.right:
                    root.right = self.BSTNode(val)
                else:
                    insertNode(root.right, val)

        root = self.BSTNode(0)
        s = 0
        count = 0
        for num in nums:
            s += num
            count += getBound(root, s - lower, True) - getBound(root, s - upper, False)
            insertNode(root, s)
        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    lower = int(input())
    upper = int(input())
    solution = Solution()
    print(solution.countRangeSum(nums, lower, upper))
