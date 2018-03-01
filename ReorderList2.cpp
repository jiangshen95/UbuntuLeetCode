#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return;
        ListNode *mid, *q;
        mid = head;
        q = head;
        while(q->next!=NULL && q->next->next!=NULL){
            mid = mid->next;
            q = q->next->next;
        }
        
        ListNode *pre = mid;
        ListNode *cur = mid->next;
        while(cur->next!=NULL){
            q = cur->next;
            cur->next = q->next;
            q->next = pre->next;
            pre->next = q;
        }
        
        cur = mid->next;
        pre = head;
        while(pre!=mid){
            mid->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = cur->next;
            cur = mid->next;
        }
        
    }
};

int main(){
    int n;
    cin>>n;
    
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        p->next = new ListNode(num);
        p = p->next;
    }
    
    head = head->next;
    
    Solution *solution = new Solution();
    solution->reorderList(head);
    
    p = head;
    while(p){
        cout<<p->val<<"  ";
        p = p->next;
    }
    
    return 0;
    
}
