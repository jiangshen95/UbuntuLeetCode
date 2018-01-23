class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        def sortedListToBST(head, tail):
            if head==tail:
                return None
            fast = head
            slow = head
            while fast!=tail and fast.next!=tail:
                fast = fast.next.next
                slow = slow.next
            root = TreeNode(slow.val)
            root.left = sortedListToBST(head, slow)
            root.right = sortedListToBST(slow.next, tail)
            return root
            
        return sortedListToBST(head, None)
        
    def printTree(self, root):
        if root!=None:
            print(root.val)
            self.printTree(root.left)
            self.printTree(root.right)
        
if __name__=='__main__':
    nums = list(input())
    
    head = ListNode(0)
    p = head
    
    for num in nums:
        q = ListNode(num)
        p.next = q
        p = q
    head = head.next
    
    solution = Solution()
    root = solution.sortedListToBST(head)
    solution.printTree(root)
