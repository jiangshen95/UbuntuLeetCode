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
        
        if(head==NULL) return head;
        
        if(head->next!=NULL&&head->next->val==head->val){
            while(head->next!=NULL&&head->next->val==head->val)
                head=head->next;
            return deleteDuplicates(head->next);
        }else{
            head->next=deleteDuplicates(head->next);
            return head;
        }
        
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
