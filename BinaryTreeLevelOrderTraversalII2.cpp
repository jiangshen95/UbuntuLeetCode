#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        
        vector<vector<int> > result;
        
        levelOrderBottom(result, root, 0);
        
        return result;
        
    }
    
    void levelOrderBottom(vector<vector<int> >& result, TreeNode *root, int level){
        if(root==NULL) return;
        if(result.size()<=level){
            result.insert(result.begin(), vector<int>());
        }
        levelOrderBottom(result, root->left, level+1);
        levelOrderBottom(result, root->right, level+1);
        result[result.size()-level-1].push_back(root->val);
    }
};

int main(){
    TreeNode *root=new TreeNode(3);
    TreeNode *a=new TreeNode(9);
    TreeNode *b=new TreeNode(20);
    TreeNode *c=new TreeNode(15);
    TreeNode *d=new TreeNode(7);
    
    root->left=a;
    root->right=b;
    b->left=c;
    b->right=d;
    
    Solution *solution=new Solution();
    vector<vector<int> > result=solution->levelOrderBottom(root);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
