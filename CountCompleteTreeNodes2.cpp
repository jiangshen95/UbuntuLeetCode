#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        TreeNode *cur = root;
        int deep_l = 0, deep_r = 0;
        while(cur){
            deep_l ++;
            cur = cur->left;
        }
        cur = root;
        while(cur){
            deep_r ++;
            cur = cur->right;
        }
        if(deep_l == deep_r){
            return (1 << deep_l) - 1;
        }
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    
    Solution *solution = new Solution();
    cout<<solution->countNodes(a);
    
    return 0;
}
