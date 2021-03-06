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
    bool isBalanced(TreeNode* root) {
        return getDepth(root)!=-1;
    }
    
    int getDepth(TreeNode *root){
        if(root==NULL) return 0;
        int ldepth=getDepth(root->left);
        if(ldepth==-1) return -1;
        int rdepth=getDepth(root->right);
        if(rdepth==-1) return -1;
        
        if(ldepth-rdepth>1 || rdepth-ldepth>1) return -1;
        
        return ldepth>rdepth?ldepth+1:rdepth+1;
    }
};

int main(){
    
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(3);
    TreeNode *c=new TreeNode(4);
    TreeNode *d=new TreeNode(5);
    TreeNode *e=new TreeNode(6);
    
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    c->left=e;
    
    Solution *solution=new Solution();
    solution->isBalanced(root)?cout<<"True" : cout<<"False";
    
    return 0;
    
}
