#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *h1, *h2;
        h1=new ListNode(0);
        h2=new ListNode(0);
        
        ListNode *p, *q;
        p=h1;
        q=h2;
        
        while(head!=NULL){
            if(head->val<x){
                p->next=head;
                p=p->next;
            }else{
                q->next=head;
                q=q->next;
            }
            head=head->next;
        }
        
        q->next=NULL;
        p->next=h2->next;
        
        return h1->next;
        
    }
};

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    
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
    head=solution->partition(head, x);
    
    while(head!=NULL){
        cout<<head->val<<endl;
        head=head->next;
    }
    
    return 0;
    
}
