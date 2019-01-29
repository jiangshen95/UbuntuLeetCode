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
        def deseralize(q, minVal, maxVal):
            if not q:
                return None
            if q[0] > maxVal or q[0] < minVal:
                return None
            num = q.pop(0)
            print(num)
            node = TreeNode(num)
            node.left = deseralize(q, minVal, num)
            node.right = deseralize(q, num, maxVal)
            return node

        if not data:
            return None
        nums = [int(num) for num in data.split()]
        return deseralize(nums, float('-infinity'), float('infinity'))


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
