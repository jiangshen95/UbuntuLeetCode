#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL) return NULL;
        
        ListNode *p=head, *q=NULL;
        int len=0;
        while(p!=NULL){
            len++;
            p=p->next;
        }
        
        int mid=len/2;
        p=head;
        for(int i=0;i<mid;i++){
            q=p;
            p=p->next;
        }
        
        cout<<"len: "<<len<<endl;
        cout<<"mid: "<<p->val<<endl;
        cin.get();
        
        TreeNode *root=new TreeNode(p->val);
        if(q!=NULL) q->next=NULL;
        else head=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(p->next);
        
        return root;
        
    }

    void printTree(TreeNode *root){
        if(root!=NULL){
            cout<<root->val<<" ";
            printTree(root->left);
            printTree(root->right);
            cout<<endl;
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
    TreeNode *root=solution->sortedListToBST(head);
    solution->printTree(root);
    
    return 0;
    
}
