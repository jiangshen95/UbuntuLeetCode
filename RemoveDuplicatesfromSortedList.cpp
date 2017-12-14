#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *q, *p;
        p=head;
        q=p;
        while(p!=NULL){
            p=p->next;
            if(p!=NULL&&q->val==p->val){
                q->next=p->next;
            }else{
                q=p;
            }
        }
        
        return head;
        
    }
};

int main(){
    
    int n;
    cin>>n;
    
    ListNode *head=new ListNode(0);
    ListNode *p, *q;
    p=head;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        q=new ListNode(num);
        p->next=q;
        p=q;
    }
    head=head->next;
    
    Solution *solution=new Solution();
    head=solution->deleteDuplicates(head);
    
    while(head!=NULL){
        cout<<head->val<<endl;
        head=head->next;
    }
    
    return 0;
    
}
