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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> queue;
        queue.push_back(root);
        queue.push_back(root);
        while(!queue.empty()){
            TreeNode *l=queue.front();
            queue.erase(queue.begin());
            TreeNode *r=queue.front();
            queue.erase(queue.begin());
            
            if(l==NULL && r==NULL) continue;
            if(l==NULL || r==NULL) return false;
            if(l->val!=r->val) return false;
            queue.push_back(l->left);
            queue.push_back(r->right);
            queue.push_back(l->right);
            queue.push_back(r->left);
        }
        
        return true;
    }
};

int main(){
    /*TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(2);
    TreeNode *c=new TreeNode(3);
    TreeNode *d=new TreeNode(4);
    TreeNode *e=new TreeNode(4);
    TreeNode *f=new TreeNode(3);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;*/
    
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(2);
    TreeNode *c=new TreeNode(3);
    TreeNode *d=new TreeNode(3);
    root->left=a;
    root->right=c;
    a->left=d;
    c->left=b;
    
    
    Solution solution;
    solution.isSymmetric(root) ? cout<<"True" : cout<<"False";
    
    return 0;
}
