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
        
        return sortedListToBST(head, NULL);
        
    }
    
    TreeNode* sortedListToBST(ListNode *head, ListNode *tail){
        
        if(head==tail) return NULL;
        
        ListNode *fast=head;
        ListNode *slow=head;
        
        while(fast!=tail&&fast->next!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        TreeNode *root=new TreeNode(slow->val);
        
        root->left=sortedListToBST(head, slow);
        root->right=sortedListToBST(slow->next, tail);
        
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
