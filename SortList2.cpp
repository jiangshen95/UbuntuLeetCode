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
        ListNode *slow, *fast, *pre;
        slow = head;
        fast = head;
        pre = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2){
        ListNode *front = new ListNode(0);
        ListNode *pre = front;
        while(l1&&l2){
            if(l1->val<l2->val){
                pre->next = l1;
                l1 = l1->next;
            }else{
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if(l1){
            pre->next = l1;
        }
        if(l2){
            pre->next = l2;
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
    p = solution->sortList(head);
    
    while(p){
        cout<<p->val<<"  ";
        p = p->next;
    }
    
    return 0;
}
