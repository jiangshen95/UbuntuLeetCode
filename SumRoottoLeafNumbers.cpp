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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        vector<TreeNode*> nodes;
        int sum=0;
        nodes.push_back(root);
        while(!nodes.empty()){
            int size=nodes.size();
            for(int i=0;i<size;i++){
                if(nodes[i]->left){
                    nodes.push_back(nodes[i]->left);
                    nodes[i]->left->val += nodes[i]->val * 10;
                }
                if(nodes[i]->right){
                    nodes.push_back(nodes[i]->right);
                    nodes[i]->right->val += nodes[i]->val * 10;
                }
                if(nodes[i]->left==NULL && nodes[i]->right==NULL){
                    sum += nodes[i]->val;
                }
            }
            nodes.erase(nodes.begin(), nodes.begin()+size);
        }
        
        return sum;
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(3);
    root->left=a;
    root->right=b;
    
    Solution *solution=new Solution();
    cout<<solution->sumNumbers(root);
    
    return 0;
}
