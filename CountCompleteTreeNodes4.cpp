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
        
        int height = getHeight(root);
        TreeNode *cur = root;
        int count = 0;
        int level = height - 2;
        
        while(level >= 0){
            TreeNode *left = cur->left;
            for(int i=0;i<level;i++) left = left->right;
            if(left){
                cur = cur->right;
                count += 1 << level; 
            }else{
                cur = cur->left;
            }
            level --;
        }
        if(cur) count ++;
        return (1 << (height - 1)) + count - 1;
    }
    
    int getHeight(TreeNode* root){
        int height = 0;
        while(root){
            height ++;
            root = root->left;
        }
        
        return height;
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
