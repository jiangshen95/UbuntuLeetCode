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
    bool isValidBST(TreeNode* root) {
        
        vector<TreeNode*> stack;
        TreeNode *p=root;
        TreeNode *pre=NULL;
        while(p!=NULL||!stack.empty()){
            while(p!=NULL){
                stack.push_back(p);
                p=p->left;
            }
            p=stack.back();
            stack.pop_back();
            if(pre!=NULL&&p->val<=pre->val) return false;
            pre=p;
            p=p->right;
        }
        
        return true;
    }
};

int main(){
    TreeNode *root=new TreeNode(10);
    TreeNode *a=new TreeNode(5);
    TreeNode *b=new TreeNode(15);
    TreeNode *c=new TreeNode(6);
    TreeNode *d=new TreeNode(20);
    TreeNode *e=NULL;
    root->left=a;
    root->right=b;
    b->left=c;
    b->right=d;
    
    Solution *solution=new Solution();
    solution->isValidBST(root) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
