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
        
        vector<TreeNode*> nodes;
        
        if(root!=NULL) nodes.push_back(root);
        
        while(!nodes.empty()){
            vector<int> level;
            int size=nodes.size();
            for(int i=0;i<size;i++){
                level.push_back(nodes[i]->val);
                if(nodes[i]->left!=NULL) nodes.push_back(nodes[i]->left);
                if(nodes[i]->right!=NULL) nodes.push_back(nodes[i]->right);
            }
            result.insert(result.begin(), level);
            nodes.erase(nodes.begin(), nodes.begin()+size);
        }
        
        return result;
        
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
