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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        vector<TreeNode*> nodes;
        if(root) nodes.push_back(root);
        while(!nodes.empty()){
            result.push_back(nodes.back()->val);
            int size = nodes.size();
            for(int i=0;i<size;i++){
                if(nodes[i]->left) nodes.push_back(nodes[i]->left);
                if(nodes[i]->right) nodes.push_back(nodes[i]->right);
            }
            nodes.erase(nodes.begin(), nodes.begin() + size);
        }
        
        return result;
        
    }
};

int main(){
    
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    
    a->left = b;
    a->right = c;
    b->right = e;
    c->right = d;
    
    Solution *solution = new Solution();
    vector<int> result = solution->rightSideView(a);
    
    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    
    return 0;
    
}
