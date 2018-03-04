#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        
        ListNode *front = new ListNode(0);
        
        ListNode *cur = head;
        ListNode *pre = front;
        ListNode *next = NULL;
        
        while(cur){
            next = cur->next;
            
            while(pre->next && pre->next->val<cur->val){
                pre = pre->next;
            }
            
            cur->next = pre->next;
            pre->next = cur;
            pre = front;
            cur = next;
            
        }
        
        return front->next;
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
    p = solution->insertionSortList(head);
    
    while(p){
        cout<<p->val<<"  ";
        p = p->next;
    }
    
    return 0;
}
