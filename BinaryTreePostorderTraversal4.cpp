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
        
        TreeNode *cur = root;
        vector<TreeNode*> stack;
        
        while(cur || !stack.empty()){
            if(cur){
                stack.push_back(cur);
                postorder.insert(postorder.begin(), cur->val);
                cur = cur->right;
            }else{
                cur = stack.back();
                stack.pop_back();
                cur = cur->left;
            }
        }
        
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
