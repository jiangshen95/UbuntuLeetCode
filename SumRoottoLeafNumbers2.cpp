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
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    
    int sumNumbers(TreeNode *root, int s){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return s*10+root->val;
        return sumNumbers(root->left, s*10+root->val)+sumNumbers(root->right, s*10+root->val);
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(3);
    root->left=a;
    root->right=b;
    
    Solution *solution=new Solution();
    cout<<solution->sumNumbers(root);
    
    return 0;
}
