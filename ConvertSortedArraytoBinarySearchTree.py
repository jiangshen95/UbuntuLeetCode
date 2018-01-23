class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums)==0:
            return None
        mid = len(nums)//2
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:])
        return root
        
    def printTree(self, root):
        if root!=None:
            print(root.val)
            self.printTree(root.left)
            self.printTree(root.right)
            
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    root = solution.sortedArrayToBST(nums)
    solution.printTree(root)
