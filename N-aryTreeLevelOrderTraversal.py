class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution:
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        if not root:
            return []
        nodes, result = [root], []
        while nodes:
            result.append([node.val for node in nodes])
            nodes = [child for node in nodes for child in node.children if node]
        return result


if __name__ == '__main__':
    a = Node(1, [])
    b = Node(2, [])
    c = Node(3, [])
    d = Node(4, [])
    e = Node(5, [])
    f = Node(6, [])

    a.children.append(b)
    a.children.append(c)
    a.children.append(d)

    b.children.append(e)
    b.children.append(f)

    solution = Solution()
    print(solution.levelOrder(a))
