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
    
    TreeNode *node1=NULL;
    TreeNode *node2=NULL;
    
    void recoverTree(TreeNode* root) {
        
        vector<TreeNode*> stack;
        TreeNode *p=root;
        TreeNode *pre=NULL, *q;
        TreeNode *node1=NULL, *node2=NULL;
        
        while(p!=NULL){
            if(p->left==NULL){
                if(pre!=NULL && p->val<=pre->val){
                    if(node1==NULL){
                        node1=pre;
                        node2=p;
                    }else{
                        node2=p;
                    }
                }
                pre=p;
                p=p->right;
            }else{
                q=p->left;
                while(q->right!=NULL && q->right!=p) q=q->right;
                if(q->right==NULL){
                    q->right=p;
                    p=p->left;
                }else{
                    q->right=NULL;
                    if(pre!=NULL && p->val<=pre->val){
                        if(node1==NULL){
                            node1=pre;
                            node2=p;
                        }else{
                            node2=p;
                        }
                    }
                    pre=p;
                    p=p->right;
                }
            }
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
