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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        
        zigzagLevelOrder(result, root, 0);
        
        return result;
    }
    
    void zigzagLevelOrder(vector<vector<int> >& result, TreeNode* root, int depth){
        if(root==NULL) return;
        if(result.size()==depth){
            result.push_back(vector<int>());
        }
        if(depth%2==0){
            result[depth].push_back(root->val);
        }else{
            result[depth].insert(result[depth].begin(), 1, root->val);
        }
        zigzagLevelOrder(result, root->left, depth+1);
        zigzagLevelOrder(result, root->right, depth+1);
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
    vector<vector<int> > result=solution->zigzagLevelOrder(root);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
