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
        nodes = []
        data = ''
        if root:
            nodes.append(root)
            data += str(root.val) + ' '
        while nodes:
            node = nodes[0]
            nodes.pop(0)
            if node.left:
                nodes.append(node.left)
                data += str(node.left.val) + ' '
            else:
                data += 'n '
            if node.right:
                nodes.append(node.right)
                data += str(node.right.val) + ' '
            else:
                data += 'n '
        return data




    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        root = None
        nodes = []
        nums = data.split()
        i = 0
        while i < len(nums):
            if i == 0:
                root = TreeNode(int(nums[i]))
                nodes.append(root)
                i += 1
            else:
                node = nodes[0]
                if nums[i] != 'n':
                    node.left = TreeNode(int(nums[i]))
                    nodes.append(node.left)
                i += 1
                if nums[i] != 'n':
                    node.right = TreeNode(int(nums[i]))
                    nodes.append(node.right)
                i += 1
                nodes.pop(0)
        return root



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