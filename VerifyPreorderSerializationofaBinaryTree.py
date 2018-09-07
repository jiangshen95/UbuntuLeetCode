class Solution:
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        nodes = preorder.split(',')
        diff = 1
        for node in nodes:
            if diff == 0:
                return False
            if node == '#':
                diff -= 1
            else:
                diff += 1
        return diff == 0


if __name__ == '__main__':
    preorder = input()
    solution = Solution()
    print(solution.isValidSerialization(preorder))
