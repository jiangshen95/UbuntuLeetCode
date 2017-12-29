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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        
        TreeNode *p=root;
        vector<TreeNode*> stack;
        while(p!=NULL||!stack.empty()){
            while(p!=NULL){
                stack.push_back(p);
                p=p->left;
            }
            p=stack.back();
            stack.pop_back();
            result.push_back(p->val);
            p=p->right;
        }
        
        return result;
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *p=new TreeNode(2);
    root->right=p;
    TreeNode *q=new TreeNode(3);
    p->left=q;
    
    Solution *solution=new Solution();
    vector<int> result=solution->inorderTraversal(root);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}
