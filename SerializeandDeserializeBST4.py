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
        result, stack = [], []
        while stack or root:
            if root:
                result.append(root.val)
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                root = root.right
        return ' '.join(map(str, result))

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        data = list(map(int, data.split()))
        root = TreeNode(data[0])
        cur = root
        stack = []
        for n in data[1:]:
            if n < cur.val:
                cur.left = TreeNode(n)
                stack.append(cur)
                cur = cur.left
            else:
                while stack and stack[-1].val < n:
                    cur = stack.pop()
                cur.right = TreeNode(n)
                cur = cur.right
        return root


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
