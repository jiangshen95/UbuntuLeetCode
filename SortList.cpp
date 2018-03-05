/*
 * Quick Sort Time Limit Exceeded
*/
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
        
        return quickSortList(head, NULL);
    }
    
    ListNode* quickSortList(ListNode *head, ListNode *end){
        //cout<<"head: "<<head->val<<endl;
        if(head==end){
            return head;
        }
        ListNode *front = new ListNode(0);
        ListNode *pre = front;
        ListNode *cur = head;
        while(cur->next!=end){
            ListNode *next = cur->next->next;
            if(cur->next->val<head->val){
                cout<<cur->next->val<<endl;
                cur->next->next = pre->next;
                pre->next = cur->next;
                cur->next = next;
                pre = pre->next;
            }else{
                cur = cur->next;
            }
        }
        pre->next = head;
        ListNode *new_head = quickSortList(front->next, head);
        head->next = quickSortList(head->next, end);
        
        return new_head;
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
