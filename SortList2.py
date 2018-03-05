class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def split(head, step):
            for i in range(step-1):
                if not head:
                    break
                head = head.next
            if not head:
                return None
            second = head.next
            head.next = None
            return second
            
        def merge(l1, l2, pre):
            while l1 and l2:
                if l1.val<l2.val:
                    pre.next = l1
                    l1 = l1.next
                else:
                    pre.next = l2
                    l2 = l2.next
                pre = pre.next
            if l1:
                pre.next = l1
            if l2:
                pre.next = l2
            while pre.next:
                pre = pre.next
            return pre
            
        if head == None or head.next == None:
            return head
        
        cur = head
        length = 0
        while cur:
            cur = cur.next
            length += 1
        
        front = ListNode(0)
        front.next = head
            
        step = 1
        while step<length:
            cur = front.next
            tail = front
            while cur:
                left = cur
                right = split(cur, step)
                cur = split(right, step)
                tail = merge(left, right, tail)
            step *= 2
        return front.next

if __name__=='__main__':
    nums = list(input())
    head = ListNode(0)
    p = head
    for num in nums:
        p.next = ListNode(num)
        p = p.next
    head = head.next
    
    solution = Solution()
    p = solution.sortList(head)
    
    while p:
        print(p.val)
        p = p.next
