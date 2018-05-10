class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.k = k
        self.helper(root)
        return self.num
            
    def helper(self, root):
        if not root:
            return
        self.helper(root.left)
        self.k -= 1
        if self.k == 0:
            self.num = root.val
            return
        self.helper(root.right)

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
