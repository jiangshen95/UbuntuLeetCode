#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *p, *q, *begin, *end;
        p=new ListNode(0);
        p->next=head;
        head=p;
        begin=p;
        while(p!=NULL){
            q=p;
            p=p->next;
            if(p!=NULL&&begin->next->val==p->val){
                end=p;
            }else{
                cout<<"begin: "<<begin->val<<"---"<<"end: "<<end->val<<endl;
                if(begin->next!=end){
                    //cout<<"begin: "<<begin->val<<"---"<<"end: "<<end->val<<"---"<<"p: "<<p->val<<endl;
                    begin->next=end->next;
                    end=p;
                }else{
                    begin=q;
                    end=p;
                }
                
            }
        }
        
        return head->next;
        
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
