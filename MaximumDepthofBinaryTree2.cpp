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
    int maxDepth(TreeNode* root) {
        int depth=0;
        vector<TreeNode*> nodes;
        if(root!=NULL){
            nodes.push_back(root);
        }
        while(!nodes.empty()){
            int size=nodes.size();
            for(int i=0;i<size;i++){
                if(nodes[i]->left!=NULL) nodes.push_back(nodes[i]->left);
                if(nodes[i]->right!=NULL) nodes.push_back(nodes[i]->right);
            }
            nodes.erase(nodes.begin(), nodes.begin()+size);
            depth++;
        }
        
        return depth;
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(3);
    root->left=a;
    a->left=b;
    
    Solution solution=Solution();
    cout<<solution.maxDepth(root);
    
    return 0;
}
