#include<iostream>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*, int> map;
        ListNode *p = head;
        while(p){
            if(map[p]) return true;
            map[p] = 1;
            p = p->next;
        }
        
        return false;
        
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
    e->next = c;
    
    Solution *solution = new Solution();
    solution->hasCycle(a) ? cout<<"True" : cout<<"False";
    
    return 0;
}
