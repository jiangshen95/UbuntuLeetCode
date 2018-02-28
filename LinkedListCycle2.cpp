#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        /*ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;*/
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow!=fast){
            if(fast==NULL || fast->next==NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = e;
    
    Solution *solution = new Solution();
    solution->hasCycle(a) ? cout<<"True" : cout<<"False";
    
    return 0;
}
