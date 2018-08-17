class Node:
    def __init__(self, val, sum):
        self.val = val
        self.sum = sum
        self.dup = 1
        self.left = None
        self.right = None


class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def insert(root, i, num, preSum):
            if not root:
                root = Node(num, 0)
                counts[i] = preSum
            elif root.val == num:
                root.dup += 1
                counts[i] = preSum + root.sum
            elif root.val > num:
                root.sum += 1
                root.left = insert(root.left, i, num, preSum)
            else:
                root.right = insert(root.right, i, num, preSum + root.sum + root.dup)
            return root
        n = len(nums)
        counts = [0] * n
        root = None
        for i in range(n - 1, -1, -1):
            root = insert(root, i, nums[i], 0)
        return counts


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.countSmaller(nums))
