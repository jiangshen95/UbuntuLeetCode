class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None or head.next == None:
            return False
        slow = head
        fast = head.next
        while slow != fast:
            if fast==None or fast.next==None:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
        
if __name__=='__main__':
    a = ListNode(1);
    b = ListNode(2);
    c = ListNode(3);
    d = ListNode(4);
    e = ListNode(5);
    
    a.next = b;
    b.next = c;
    c.next = d;
    d.next = e;
    e.next = c;
    
    solution = Solution()
    print(solution.hasCycle(a))
