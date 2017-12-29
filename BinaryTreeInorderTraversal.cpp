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
        
        if(root==NULL){
            return result;
        }
        
        if(root->left!=NULL){
            vector<int> l=inorderTraversal(root->left);
            result.insert(result.begin(), l.begin(), l.end());
        }
        result.push_back(root->val);
        if(root->right!=NULL){
            vector<int> r=inorderTraversal(root->right);
            result.insert(result.end(), r.begin(), r.end());
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
