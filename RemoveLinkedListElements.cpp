#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = new ListNode(0);
        pre->next = head;
        head = pre;
        ListNode *cur = pre->next;
        
        while(cur){
            if(cur->val == val){
                pre->next = cur->next;
                cur = pre->next;
            }else{
                cur = cur->next;
                pre = pre->next;
            }
        }
        
        return head->next;
        
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
    
    int val;
    cin>>val;
    
    Solution *solution = new Solution();
    head = solution->removeElements(head, val);
    
    while(head) {
        cout<<head->val<<"  ";
        head = head->next;
    }
    
    return 0;
    
}
