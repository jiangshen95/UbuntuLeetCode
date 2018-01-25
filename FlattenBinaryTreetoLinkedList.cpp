#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(root==NULL) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode *left=root->left;
        TreeNode *right=root->right;
        
        if(left==NULL) return;
        
        root->right=left;
        root->left=NULL;
        while(left->right!=NULL){
            left=left->right;
        }
        left->right=right;
        
        //root = flatten2(root);
        
    }
    
    TreeNode* flatten2(TreeNode *root){
        
        if(root==NULL) return NULL;
        
        TreeNode *left=flatten2(root->left);
        TreeNode *right=flatten2(root->right);
        
        if(left==NULL) return root;
        
        root->right=left;
        while(left->right!=NULL){
            left=left->right;
        }
        left->right=right;
        
        return root;
        
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(3);
    TreeNode *c=new TreeNode(4);
    TreeNode *d=new TreeNode(5);
    TreeNode *e=new TreeNode(6);
    TreeNode *f=new TreeNode(7);
    
    root->left=a;
    root->right=b;
    //a->left=c;
    //c->left=d;
    //b->left=e;
    //b->right=f;
    
    //root->left=a;
    //root->right=d;
    //a->left=b;
    //a->right=c;
    //d->right=e;
    
    Solution *solution=new Solution();
    solution->flatten(root);
    
    while(root!=NULL){
        cout<<root->val<<" ";
        root=root->right;
    }
    
    return 0;
}
