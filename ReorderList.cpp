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
        ListNode *p = head;
        while(p->next->next){
            p = p->next;
        }
        p->next->next = head->next;
        head->next = p->next;
        p->next = NULL;
        reorderList(head->next->next);
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
