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
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return sum==root->val;
        
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

int main(){
    
    TreeNode *root=new TreeNode(5);
    TreeNode *a=new TreeNode(4);
    TreeNode *b=new TreeNode(8);
    TreeNode *c=new TreeNode(11);
    TreeNode *d=new TreeNode(13);
    TreeNode *e=new TreeNode(4);
    TreeNode *f=new TreeNode(7);
    TreeNode *g=new TreeNode(2);
    TreeNode *h=new TreeNode(1);
    
    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->right=h;
    
    int sum;
    cin>>sum;
    
    Solution *solution=new Solution();
    solution->hasPathSum(root, sum) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
