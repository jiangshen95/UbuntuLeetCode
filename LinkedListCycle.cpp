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
        ListNode *p = head;
        while(p && p->next!=p){
            if(p->next!=NULL){
                p->next = p->next->next;
            }
            p = p->next;
        }
        return p!=NULL;
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
