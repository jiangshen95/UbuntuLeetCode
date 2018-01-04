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
        
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode){
        if(root==NULL) return true;
        if(minNode!=NULL && root->val<=minNode->val || maxNode!=NULL&&root->val>=maxNode->val) return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
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
