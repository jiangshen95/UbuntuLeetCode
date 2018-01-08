class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        nodes = []
        if root!=None:
            nodes.append(root)
        while len(nodes)!=0:
            line = []
            size = len(nodes)
            for i in range(size):
                line.append(nodes[i].val)
                if nodes[i].left != None:
                    nodes.append(nodes[i].left)
                if nodes[i].right != None:
                    nodes.append(nodes[i].right)
            result.append(line)
            nodes = nodes[size : ]
        return result

if __name__=='__main__':
    root = TreeNode(3)
    a = TreeNode(9)
    b = TreeNode(20)
    c = TreeNode(15)
    d = TreeNode(7)
    
    root.left=a
    root.right=b
    b.left=c
    b.right=d
    
    solution = Solution()
    result = solution.levelOrder(root)
    print(result)
