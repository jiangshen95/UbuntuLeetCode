class Solution:
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        nodes = preorder.split(',')
        stack = []
        for node in nodes:
            if node == '#':
                if not stack and len(nodes) == 1:
                    return True
                elif not stack:
                    return False
                while stack and stack[-1] == '#':
                    stack.pop()
                    if not stack:
                        return False
                    stack.pop()
            stack.append(node)
        return len(stack) == 1 and stack[0] == '#'


if __name__ == '__main__':
    preorder = input()
    solution = Solution()
    print(solution.isValidSerialization(preorder))
