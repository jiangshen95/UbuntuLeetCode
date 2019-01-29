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
        if not root:
            return None
        stack = [root]
        vals = []
        while stack:
            t = stack.pop()
            vals.append(t.val)
            if t.right:
                stack.append(t.right)
            if t.left:
                stack.append(t.left)
        return ' '.join(map(str, vals))

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        def deseralize(q):
            if not q:
                return None
            num = q.pop(0)
            node = TreeNode(num)
            smaller = []
            while q and q[0] < num:
                smaller.append(q[0])
                q.pop(0)
            node.left = deseralize(smaller)
            node.right = deseralize(q)
            return node

        if not data:
            return None
        nums = [int(num) for num in data.split()]
        return deseralize(nums)


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
