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
        
        TreeNode *cur=root;
        
        while(cur){
            if(cur->left){
                TreeNode *pre=cur->left;
                while(pre->right){
                    pre=pre->right;
                }
                pre->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
        
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
    a->left=c;
    c->left=d;
    b->left=e;
    b->right=f;
    
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
