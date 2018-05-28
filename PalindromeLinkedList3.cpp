#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode *p = head, *cur = head, *pre = NULL, *mid;
        while(p && p->next) {
        	p = p->next->next;
        	ListNode *next = cur->next;
        	cur->next = pre;
            pre = cur;
            cur = next;
        }
        if(p) cur = cur->next;
        
        while(pre && cur){
            if(pre->val != cur->val) return false;
            pre = pre->next;
            cur = cur->next;
        }
        
        return true;
        
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
    solution->isPalindrome(head) ? cout<<"True" : cout<<"False";
    
    return 0;
    
} 
