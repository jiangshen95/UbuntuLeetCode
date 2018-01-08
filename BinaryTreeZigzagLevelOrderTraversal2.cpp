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
        
        vector<TreeNode*> level_nodes;
        if(root!=NULL) level_nodes.push_back(root);
        
        while(!level_nodes.empty()){
            vector<int> line;
            int size=level_nodes.size();
            for(int i=0;i<size;i++){
                if(result.size()%2==0){
                    line.push_back(level_nodes[i]->val);
                }else{
                    line.insert(line.begin(), 1, level_nodes[i]->val);
                }
                
                if(level_nodes[i]->left!=NULL) level_nodes.push_back(level_nodes[i]->left);
                if(level_nodes[i]->right!=NULL) level_nodes.push_back(level_nodes[i]->right);
            }
            result.push_back(line);
            level_nodes.erase(level_nodes.begin(), level_nodes.begin()+size);
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
    vector<vector<int> > result=solution->zigzagLevelOrder(root);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
