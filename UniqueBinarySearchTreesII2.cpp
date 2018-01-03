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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*> > dp(1, vector<TreeNode*>(1, NULL));
        
        for(int i=1;i<=n;i++){
            vector<TreeNode*> temp;
            for(int j=0;j<i;j++){
                for(int k=0;k<dp[j].size();k++){
                    for(int l=0;l<dp[i-j-1].size();l++){
                        TreeNode *node=new TreeNode(j+1);
                        node->left=dp[j][k];
                        node->right=clone(dp[j][l], j+1);
                        temp.push_back(node);
                    }
                }
            }
            dp.push_back(temp);
        }
        
        return dp[n];
        
    }
    
    TreeNode* clone(TreeNode *root, int offset){
        if(root==NULL){
            return NULL;
        }
        TreeNode *newroot=new TreeNode(root->val+offset);
        newroot->left=clone(root->left, offset);
        newroot->right=clone(root->right, offset);
        return newroot;
        
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
    int n;
    cin>>n;
    
    Solution *solution=new Solution();
    vector<TreeNode*> result=solution->generateTrees(n);
    cout<<"size: "<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        solution->printTree(result[i]);
    }
    
    return 0;
    
}

