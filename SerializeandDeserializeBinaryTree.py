class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return 'n '
        else:
            return str(root.val) + ' ' + self.serialize(root.left) + self.serialize(root.right)


    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        def buildTree(nodes):
            node = nodes[0]
            nodes.pop(0)
            if node == 'n':
                return None
            else:
                cur = TreeNode(int(node))
                cur.left = buildTree(nodes)
                cur.right = buildTree(nodes)
                return cur
        nodes = data.split()
        return buildTree(nodes)

    def printTree(self, root):
        if not root:
            return
        print(root.val)
        self.printTree(root.left)
        self.printTree(root.right)


if __name__ == '__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    f = TreeNode(6)

    a.left = b
    a.right = c
    c.left = d
    c.right = e
    e.left = f

    codec = Codec()
    data = codec.serialize(a)
    print(data)
    codec.printTree(codec.deserialize(data))