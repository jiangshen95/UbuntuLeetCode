#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p, *q;
        p = head;
        if(head==NULL||(head!=NULL&&head->next==NULL)){
            return head;
        }
        int count=0;
        while(p->next!=NULL){
            count++;
            p = p->next;
        }
        count++;
        q=p;
        k = k%count;
        p=head;
        for(int i=1;i<count-k;i++){
            p = p->next;
        }
        ListNode *newhead= p->next ? p->next : head;
        q->next = head;
        p->next = NULL;
        
        return newhead;
        
    }
};

int main(){
    int n, k;
    cin>>n;
    
    ListNode *p, *head, *q;
    int num;
    cin>>num;
    p=new ListNode(num);
    p->next=NULL;
    head=p;
    for(int i=1;i<n;i++){
        cin>>num;
        q=new ListNode(num);
        p->next=q;
        q->next=NULL;
        p=q;
    }
    
    cin>>k;
    
    Solution *solution = new Solution();
    head = solution->rotateRight(head, k);
    
    while(head!=NULL){
        cout<<head->val<<", ";
        head=head->next;
    }
    
    return 0;
}
