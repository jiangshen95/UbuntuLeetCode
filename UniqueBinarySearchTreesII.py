class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def generateTrees(begin, end):
            trees = []
            if begin>end:
                trees.append(None)
                return trees
            for i in range(begin, end+1):
                left_trees = generateTrees(begin, i-1)
                right_trees = generateTrees(i+1, end)
                
                for l in left_trees:
                    for r in right_trees:
                        temp = TreeNode(i)
                        temp.left = l
                        temp.right = r
                        trees.append(temp)
            return trees
        if n==0:
            return []
        return generateTrees(1, n)
        
    def printTree(self, root):
        if root!=None:
            print(root.val)
            self.printTree(root.left)
            self.printTree(root.right)
            print("\n")
        
if __name__=='__main__':
    n = int(raw_input())
    solution = Solution()
    result = solution.generateTrees(n)
    for r in result:
        solution.printTree(r)
    
