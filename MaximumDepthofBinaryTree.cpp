#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }
    
    int maxDepth(TreeNode *root, int depth){
        if(root==NULL) return depth;
        int ldepth=maxDepth(root->left, depth+1);
        int rdepth=maxDepth(root->right, depth+1);
        return ldepth>rdepth ? ldepth : rdepth;
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(3);
    root->left=a;
    root->right=b;
    
    Solution solution=Solution();
    cout<<solution.maxDepth(root);
    
    return 0;
}
