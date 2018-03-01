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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;
        preorder.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        preorder.insert(preorder.end(), left.begin(), left.end());
        preorder.insert(preorder.end(), right.begin(), right.end());
        return preorder;
    }
};

int main(){
    
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    
    Solution *solution = new Solution();
    vector<int> preorder = solution->preorderTraversal(a);
    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i]<<" ";
    }
    
    return 0;
    
}
