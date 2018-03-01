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
        
        if(root==NULL) return preorder;
        
        vector<TreeNode*> stack;
        stack.push_back(root);
        
        while(!stack.empty()){
            TreeNode *cur = stack.back();
            stack.pop_back();
            preorder.push_back(cur->val);
            if(cur->right) stack.push_back(cur->right);
            if(cur->left) stack.push_back(cur->left);
        }
        
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
    d->right = e;
    
    Solution *solution = new Solution();
    vector<int> preorder = solution->preorderTraversal(a);
    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i]<<" ";
    }
    
    return 0;
    
}
