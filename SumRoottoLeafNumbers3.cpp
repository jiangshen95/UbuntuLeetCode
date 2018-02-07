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
        if(root==NULL) return 0;
        vector<TreeNode*> stack;
        TreeNode *cur=root, *pre=NULL;
        int sum=0, one=0;
        
        while(!stack.empty() || cur){
            while(cur){
                stack.push_back(cur);
                one=one*10+cur->val;
                cur=cur->left;
            }
            cur=stack.back();
            if(cur->left==NULL && cur->right==NULL) sum+=one;
            if(cur->right!=NULL && cur->right!=pre){
                cur=cur->right;
            }else{
                pre=cur;
                stack.pop_back();
                one/=10;
                cur=NULL;
            }
        }
        
        return sum;
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
