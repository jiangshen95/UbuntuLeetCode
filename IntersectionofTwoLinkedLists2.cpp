#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count_a = 0, count_b = 0;
        ListNode *p;
        p = headA;
        while(p){
            count_a++;
            p = p->next;
        }
        p = headB;
        while(p){
            count_b++;
            p = p->next; 
        }
        
        if(count_a>count_b){
            for(int i=0;i<count_a-count_b;i++){
                headA = headA->next;
            }
        }else{
            for(int i=0;i<count_b-count_a;i++) headB = headB->next;
        }
        
        while(headA && headB && headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        
        if(headA == headB) return headA;
        else return NULL;
        
    }
};

int main(){
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    
    ListNode *b1 = new ListNode(3);
    ListNode *b2 = new ListNode(4);
    ListNode *b3 = new ListNode(5);
    
    ListNode *c1 = new ListNode(6);
    ListNode *c2 = new ListNode(7);
    ListNode *c3 = new ListNode(8);
    
    a1->next = a2;
    a2->next = c1;
    c1->next = c2;
    c2->next = c3;
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;
    
    Solution *solution = new Solution();
    cout<<solution->getIntersectionNode(a1, b1)->val<<endl;
    
    return 0;
    
}
