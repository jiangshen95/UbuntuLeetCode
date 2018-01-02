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
        vector<TreeNode*> trees;
        if(n==0) return trees;
        trees=generateTrees(1, n);
        return trees;
    }
    
    vector<TreeNode*> generateTrees(int begin, int end){
        vector<TreeNode*> trees;
        if(begin>end){
            trees.push_back(NULL);
            return trees;
        }
        for(int i=begin;i<=end;i++){
            vector<TreeNode*> left_trees;
            vector<TreeNode*> right_trees;
            
            left_trees=generateTrees(begin, i-1);
            right_trees=generateTrees(i+1, end);
            
            for(int j=0;j<left_trees.size();j++){
                for(int k=0;k<right_trees.size();k++){
                    TreeNode *temp=new TreeNode(i);
                    temp->left=left_trees[j];
                    temp->right=right_trees[k];
                    trees.push_back(temp);
                }
            }
        }
        
        return trees;
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
    for(int i=0;i<result.size();i++){
        solution->printTree(result[i]);
    }
    
    return 0;
    
}
