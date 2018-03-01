#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *first = head;
        ListNode *second = head;
        
        bool isCycle = false;
        
        while(second!=NULL and second->next!=NULL){
            first = first->next;
            second = second->next->next;
            if(first == second) {
                isCycle = true;
                break;
            }
        }
        
        if(!isCycle) return NULL;
        
        first = head;
        while(first!=second){
            first = first->next;
            second = second->next;
        }
        
        return first;
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
    e->next = b;
    
    Solution *solution = new Solution();
    ListNode *begin = solution->detectCycle(a);
    cout<<begin->val;
    
    return 0;
}

