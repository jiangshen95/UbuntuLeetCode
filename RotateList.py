class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return head
        p = head
        count = 0
        while p.next!=None:
            count+=1
            p = p.next
        q = p
        count+=1
        k = k%count
        p = head
        for i in range(1, count-k):
            p = p.next
        newhead = p.next if p.next!=None else head
        q.next = head
        p.next = None
        
        return newhead
        
if __name__=='__main__':
    nums = list(input())
    print(nums)
    p = ListNode(0)
    p.next = None
    head = p
    for i in nums:
        q = ListNode(i)
        p.next = q
        q.next = None
        p = q
    k = int(input())
    head=head.next
    solution = Solution()
    head = solution.rotateRight(head, k)
    while head!=None:
        print("%d, " % (head.val))
        head = head.next
