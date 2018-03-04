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
        ListNode *p = head;
        bool go_next=true;
        while(p->next){
            cout<<"num0: "<<p->next->val<<endl;
            ListNode *q = head;
            go_next = true;
            while(q->next!=p->next->next){
                cout<<"num: "<<p->next->val<<endl;
                if(q==head && p->next->val<q->val){
                    cout<<"num1: "<<p->next->val<<endl;
                    ListNode *cur = p->next;
                    p->next = cur->next;
                    cur->next = q;
                    go_next = false;
                    head = cur;
                    break;
                }
                else if(q->val<=p->next->val && q->next->val>=p->next->val && q->next!=p->next){
                    cout<<"num2: "<<p->next->val<<endl;
                    ListNode *cur = p->next;
                    p->next = cur->next;
                    cur->next = q->next;
                    q->next = cur;
                    go_next = false;
                    break;
                }
                q = q->next;
            }
            if(go_next) p = p->next;
        }
        
        return head;
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
