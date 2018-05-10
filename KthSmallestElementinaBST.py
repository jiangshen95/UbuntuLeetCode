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
        stack = []
        cur = root
        count = 0
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            count += 1
            if count == k:
                return cur.val
            cur = cur.right
        return 0

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
