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
        p = ListNode(0)
        p.next = head
        head = p
        
        begin = p
        end = p
        
        while p!=None:
            q = p
            p = p.next
            if p!=None and begin.next.val==p.val:
                end=p
            else:
                if begin.next!=end:
                    begin.next=end.next
                    end=p
                else:
                    begin=q
                    end=p
        return head.next
        
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
