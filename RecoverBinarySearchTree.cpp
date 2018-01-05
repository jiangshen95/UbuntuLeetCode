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
    void recoverTree(TreeNode* root) {
        
        vector<TreeNode*> stack;
        TreeNode *p=root;
        TreeNode *pre=NULL;
        TreeNode *node1=NULL, *node2=NULL;
        
        while(p!=NULL || !stack.empty()){
            while(p!=NULL){
                stack.push_back(p);
                p=p->left;
            }
            
            p=stack.back();
            stack.pop_back();
            if(pre!=NULL && p->val<=pre->val){
                if(node1==NULL){
                    node1=pre;
                    node2=p;
                }else node2=p;
            }
            pre=p;
            p=p->right;
        }
        
        int t=node1->val;
        node1->val=node2->val;
        node2->val=t;
        
    }
    
    void printTree(TreeNode *root){
        if(root!=NULL){
            cout<<root->val<<" ";
            printTree(root->left);
            printTree(root->right);
            cout<<endl;
        }
    }
};

int main(){
    TreeNode *root=new TreeNode(2);
    TreeNode *a=new TreeNode(1);
    TreeNode *b=new TreeNode(3);
    root->left=b;
    root->right=a;
    
    Solution *solution=new Solution();
    solution->recoverTree(root);
    
    solution->printTree(root);
}
