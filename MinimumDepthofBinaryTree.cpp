#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        int ldepth=minDepth(root->left), rdepth=minDepth(root->right);
        
        /*if(ldepth<rdepth){
            if(ldepth!=0) return ldepth+1;
            else return rdepth+1;
        }else{
            if(rdepth!=0) return rdepth+1;
            else return ldepth+1;
        }*/
        
        return (ldepth==0 || rdepth==0) ? ldepth+rdepth+1 : (ldepth>rdepth?rdepth+1:ldepth+1); 
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(3);
    TreeNode *c=new TreeNode(4);
    TreeNode *d=new TreeNode(5);
    TreeNode *e=new TreeNode(6);
    
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    
    Solution *solution=new Solution();
    cout<<solution->minDepth(root);
    
    return 0;
}
