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
        
        ListNode *p = head, *mid = head;
        while(p && p->next) {
            mid = mid->next;
            p = p->next->next;
        }
        if(p) mid = mid->next;
        
        ListNode *pre = NULL;
        ListNode *cur = mid;
        while(cur){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            
        }
        
        p = head;
        while(pre){
            if(pre->val != p->val) return false;
            p = p->next;
            pre = pre->next;
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
