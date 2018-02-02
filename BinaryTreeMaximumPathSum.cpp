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
    int maxPathSum(TreeNode* root) {
        
        int res=-10000000;
        maxPathSum(root, res);
        return res;
        
    }
    
    int maxPathSum(TreeNode *root, int& res){
        if(root==NULL) return 0;
        int l_max=maxPathSum(root->left, res);
        int r_max=maxPathSum(root->right, res);
        
        if(l_max+r_max+root->val>res)
            res=l_max+r_max+root->val;
        
        return max(max(l_max, r_max)+root->val, 0);
    }
    
    int max(int a, int b){
        return a>b?a:b;
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
    a->right=d;
    b->left=e;
    b->right=f;
    
    Solution *solution=new Solution();
    cout<<solution->maxPathSum(root);
    
    return 0;
}
