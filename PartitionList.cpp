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
        
        ListNode *p, *q;
        p=new ListNode(0);
        p->next=head;
        head=p;
        
        ListNode *small, *big;
        small=p;
        big=p;
        p=p->next;
        while(p!=NULL&&p->next!=NULL){
            if(p->val<x&&p->next->val>=x){
                small=p;
                p=p->next;
            }else if(p->val>=x&&p->next->val<x){
                big=p;
                cout<<"small: "<<small->val<<endl;
                cout<<"big: "<<big->val<<endl;
                q=small->next;
                small->next=big->next;
                big->next=big->next->next;
                small->next->next=q;
                small=small->next;
            }else{
                p=p->next;
            }
            cout<<"p: "<<p->val<<endl;
            cin.get();
            //p=p->next;
        }
        
        return head->next;
        
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
