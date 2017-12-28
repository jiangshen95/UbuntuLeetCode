#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p, *q, *begin, *t;
        p=new ListNode(0);
        p->next=head;
        head=p;
        int count=0;
        while(p!=NULL&&count<=n){
            if(count<=m){
                q=p;
                p=p->next;
                count++;
            }
            if(count==m){
                begin=q;
                cout<<"begin: "<<begin->val<<endl;
            }
            if(count>m&&count<=n){
                q->next=p->next;
                t=p->next;
                p->next=begin->next;
                begin->next=p;
                
                p=t;
                count++;
            }
            
            //cout<<"q: "<<q->val<<endl;
            //cout<<"p: "<<p->val<<endl;
            cin.get();
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
    
    int m;
    cin>>m>>n;
    
    Solution *solution=new Solution();
    head=solution->reverseBetween(head, m, n);
    
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    
    return 0;
}
