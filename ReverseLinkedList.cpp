#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        
        //ListNode *pre = head;
        //ListNode *cur = head->next;
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        //head->next = NULL;
        return pre;
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
    head = solution->reverseList(head);
    
    while(head){
        cout<<head->val<<"  ";
        head = head->next;
    }
    
    return 0;
    
}
