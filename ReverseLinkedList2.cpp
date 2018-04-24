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
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *node = reverseList(head->next);
        head->next = NULL;
        ListNode *p = node;
        while(p->next) p = p->next;
        p->next = head;
        return node;
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
