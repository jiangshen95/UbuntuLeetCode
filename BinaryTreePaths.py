class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        def getPath(cur, path):
            if cur == None:
                return
            if cur.left == None and cur.right == None:
                path += str(cur.val)
                paths.append(path)
            else:
                path += str(cur.val) + '->'
            getPath(cur.left, path)
            getPath(cur.right, path)

        paths = []
        getPath(root, '')
        return paths

if __name__ == '__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(5)

    a.left = b
    a.right = c
    b.right = d

    solution = Solution()
    print(solution.binaryTreePaths(a))
