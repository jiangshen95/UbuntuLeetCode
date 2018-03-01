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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        
        if(root==NULL) return postorder;
        
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        
        postorder.insert(postorder.end(), left.begin(), left.end());
        postorder.insert(postorder.end(), right.begin(), right.end());
        
        postorder.push_back(root->val);
        
        return postorder;
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
    vector<int> postorder = solution->postorderTraversal(a);
    for(int i=0;i<postorder.size();i++){
        cout<<postorder[i]<<" ";
    }
    
    return 0;
    
}
