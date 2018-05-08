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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL) return root;
        
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        
        while(!nodes.empty()){
            int size = nodes.size();
            for(int i=0;i<size;i++){
                if(nodes[i]->left) nodes.push_back(nodes[i]->left);
                if(nodes[i]->right) nodes.push_back(nodes[i]->right);
                TreeNode *temp = nodes[i]->left;
                nodes[i]->left = nodes[i]->right;
                nodes[i]->right = temp;
            }
            nodes.erase(nodes.begin(), nodes.begin() + size);
        }
        
        return root;
        
    }
    
    void printTree(TreeNode *root){
        if(root == NULL) return;
        cout<<root->val<<" ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main(){
    
    TreeNode *a = new TreeNode(4);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(7);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(3);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(9);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    Solution *solution = new Solution();
    solution->printTree(a);
    cout<<endl;
    solution->printTree(solution->invertTree(a));
    
    return 0;
    
}
