#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        rightSideView(root, result, 0);
        
        return result;
        
    }
    
    void rightSideView(TreeNode* root, vector<int>& result, int depth){
        
        if(root == NULL) return;
        
        if(depth == result.size()) result.push_back(root->val);
        
        rightSideView(root->right, result, depth + 1);
        rightSideView(root->left, result, depth + 1);
        
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
    b->right = e;
    c->right = d;
    
    Solution *solution = new Solution();
    vector<int> result = solution->rightSideView(a);
    
    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    
    return 0;
    
}
