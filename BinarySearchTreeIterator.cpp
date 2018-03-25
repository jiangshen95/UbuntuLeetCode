#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    vector<TreeNode*> stack;
    BSTIterator(TreeNode *root) {
        TreeNode *cur = root;
        while(cur){
            stack.push_back(cur);
            cur = cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        return !stack.empty();
        
    }

    /** @return the next smallest number */
    int next() {
        
        if(!stack.empty()){
            
            TreeNode *cur = stack.back();
            stack.pop_back();
            TreeNode *next = cur->right;
            while(next){
                stack.push_back(next);
                next = next->left;
            } 
            
            return cur->val;
        }
        
        return 0;
        
    }
};

int main(){
    
    return 0;
    
}
