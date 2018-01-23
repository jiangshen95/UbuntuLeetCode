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

    ListNode *node;

    TreeNode* sortedListToBST(ListNode* head) {
        
        node=head;
        
        int len=0;
        
        ListNode *p=head;
        while(p!=NULL){
            len++;
            p=p->next;
        }
        
        return sortedListToBST(0, len-1);
        
    }
    
    TreeNode* sortedListToBST(int begin, int end){
        
        if(begin>end) return NULL;
        
        int mid=(begin+end)/2+(begin+end)%2;
        
        TreeNode *left=sortedListToBST(begin, mid-1);
        
        TreeNode *root=new TreeNode(node->val);
        
        root->left=left;
        
        node=node->next;
        
        TreeNode *right=sortedListToBST(mid+1, end);
        root->right=right;
        
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
