#include<iostream>
#include<vector>
#include<unordered_map>

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
        
        unordered_map<int, int> rightmostValueAtDepth;
        
        int max_depth = -1;
        
        vector<TreeNode*> nodeStack;
        vector<int> depthStack;
        
        nodeStack.push_back(root);
        depthStack.push_back(0);
        
        
        while(!nodeStack.empty()){
            TreeNode *node = nodeStack.back();
            nodeStack.pop_back();
            int depth = depthStack.back();
            depthStack.pop_back();
            
            if(node != NULL){
                max_depth = max(max_depth, depth);
                
                if(rightmostValueAtDepth.find(depth) == rightmostValueAtDepth.end()) rightmostValueAtDepth[depth] = node->val;
                nodeStack.push_back(node->left);
                depthStack.push_back(depth + 1);
                nodeStack.push_back(node->right);
                depthStack.push_back(depth + 1);
            }
        }
        
        vector<int> result;
        for(int i=0;i<=max_depth;i++) result.push_back(rightmostValueAtDepth[i]);
        
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
