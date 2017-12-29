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
        
        TreeNode *curr=root;
        TreeNode *p;
        while(curr!=NULL){
            if(curr->left==NULL){
                result.push_back(curr->val);
                curr=curr->right;
            }else{
                p=curr->left;
                while(p->right!=NULL){
                    p=p->right;
                }
                p->right=curr;
                TreeNode *temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
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
