#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *l, TreeNode *r){
        if(l==NULL && r==NULL) return true;
        if(l==NULL || r==NULL) return false;
        if(l->val!=r->val) return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
};

int main(){
    /*TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(2);
    TreeNode *c=new TreeNode(3);
    TreeNode *d=new TreeNode(4);
    TreeNode *e=new TreeNode(4);
    TreeNode *f=new TreeNode(3);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;*/
    
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(2);
    TreeNode *c=new TreeNode(3);
    TreeNode *d=new TreeNode(3);
    root->left=a;
    root->right=c;
    a->left=d;
    c->left=b;
    
    
    Solution solution;
    solution.isSymmetric(root) ? cout<<"True" : cout<<"False";
    
    return 0;
}
