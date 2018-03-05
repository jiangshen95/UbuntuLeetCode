#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *cur = head;
        
        int length = 0;
        
        while(cur){
            cur = cur->next;
            length++;
        }
        
        ListNode *front = new ListNode(0);
        front->next = head;
        ListNode *left, *right, *tail;
        
        for(int step=1;step<length;step*=2){
            cur = front->next;
            tail = front;
            while(cur){
                left = cur;
                right = split(cur, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return front->next;
    }
    
    ListNode *split(ListNode *head, int step){
        for(int i=1;i<step&&head;i++) head = head->next;
        if(!head) return NULL;
        ListNode *next = head->next;
        head->next = NULL;
        return next;
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2, ListNode *cur){
        while(l1&&l2){
            if(l1->val<l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }
        if(l2){
            cur->next = l2;
        }
        
        while(cur->next) cur = cur->next;
        
        return cur;
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
    p = solution->sortList(head);
    
    while(p){
        cout<<p->val<<"  ";
        p = p->next;
    }
    
    return 0;
}
