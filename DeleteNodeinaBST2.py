class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        def deleteRootNode(node):
            if not node.right:
                return node.left
            if not node.left:
                return node.right
            t = node.right
            while t.left:
                t = t.left
            t.left = node.left
            return node.right

        if not root:
            return None
        cur, pre = root, None
        while cur and cur.val != key:
            pre = cur
            if cur.val > key:
                cur = cur.left
            else:
                cur = cur.right
        if not cur:
            return root
        if not pre:
            return deleteRootNode(root)
        elif pre.left == cur:
            pre.left = deleteRootNode(cur)
        elif pre.right == cur:
            pre.right = deleteRootNode(cur)
        return root
