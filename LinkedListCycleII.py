class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return None
        fast = head
        slow = head
        while fast.next!=None and fast.next.next!=None:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                begin = head
                while begin!=slow:
                    begin = begin.next
                    slow = slow.next
                return begin
                break;
        return None
        
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
    e.next = e;
    
    solution = Solution()
    print(solution.detectCycle(a).val)
