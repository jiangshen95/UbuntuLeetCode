class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p = head
        q = p
        while p!=None:
            p = p.next
            if p!=None and q.val==p.val:
                q.next = p.next
            else:
                q = p
        return head
        
if __name__=="__main__":
    nums = list(input())
    head = ListNode(0)
    p = head
    for num in nums:
        q = ListNode(num)
        p.next = q
        p = q
    head = head.next
    
    solution = Solution()
    head = solution.deleteDuplicates(head)
    
    while head!=None:
        print(head.val)
        head = head.next

