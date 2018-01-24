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
    bool hasPathSum(TreeNode* root, int sum) {
        
        vector<TreeNode*> stack;
        TreeNode *cur=root, *pre=NULL;
        
        int SUM=0;
        
        while(cur || !stack.empty()){
            while(cur){
                stack.push_back(cur);
                SUM+=cur->val;
                cur=cur->left;
            }
            cur=stack.back();
            if(cur->left==NULL && cur->right==NULL &&SUM==sum) return true;
            
            if(cur->right!=NULL && cur->right!=pre){
                cur=cur->right;
            }else{
                pre=cur;
                stack.pop_back();
                SUM-=cur->val;
                cur=NULL;
            }
        }
        
        return false;
    }
};

int main(){
    
    TreeNode *root=new TreeNode(5);
    TreeNode *a=new TreeNode(4);
    TreeNode *b=new TreeNode(8);
    TreeNode *c=new TreeNode(11);
    TreeNode *d=new TreeNode(13);
    TreeNode *e=new TreeNode(4);
    TreeNode *f=new TreeNode(7);
    TreeNode *g=new TreeNode(2);
    TreeNode *h=new TreeNode(1);
    
    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->right=h;
    
    int sum;
    cin>>sum;
    
    Solution *solution=new Solution();
    solution->hasPathSum(root, sum) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
