class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def countNode(self, root):
        if not root:
            return 0
        return 1 + self.countNode(root.left) + self.countNode(root.right)
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        count = self.countNode(root.left)
        if count == k - 1:
            return root.val
        elif count > k - 1:
            return self.kthSmallest(root.left, k)
        else:
            return self.kthSmallest(root.right, k - count - 1)

if __name__ == '__main__':
    nums = list(input())
    
    root = TreeNode(nums[0])
    nodes = [root]
    for i in range(1, len(nums)):
        node = nodes[0]
        if i % 2 == 1:
            if nums[i] != -1:
                node.left = TreeNode(nums[i])
                nodes.append(node.left)
        else:
            if nums[i] != -1:
                node.right = TreeNode(nums[i])
                nodes.append(node.right)
            nodes.pop(0)
            
    k = int(raw_input())
    
    solution = Solution()
    print(solution.kthSmallest(root, k))
