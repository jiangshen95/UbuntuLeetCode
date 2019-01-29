class TreeNode:
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
        def serialize(root):
            if not root:
                return
            nodes.append(root.val)
            serialize(root.left)
            serialize(root.right)
        nodes = []
        serialize(root)
        return ' '.join(map(str, nodes))

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        def deseralize(stop):
            if inorder and inorder[-1] != stop:
                root = TreeNode(preorder.pop())
                root.left = deseralize(root.val)
                inorder.pop()
                root.right = deseralize(stop)
                return root

        if not data:
            return None
        preorder = [int(num) for num in data.split()]
        inorder = sorted(preorder)
        preorder.reverse()
        inorder.reverse()
        return deseralize(None)


if __name__ == '__main__':
    a = TreeNode(2)
    b = TreeNode(1)
    c = TreeNode(3)
    a.left = b
    a.right = c
    codec = Codec()
    s = codec.serialize(a)
    print(s)
    codec.deserialize(s)
