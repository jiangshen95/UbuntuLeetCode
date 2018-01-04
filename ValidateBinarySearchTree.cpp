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
    bool isValidBST(TreeNode* root) {
        
        vector<int> midOrder=middleOrder(root);

        for(int i=1;i<midOrder.size();i++){
            if(midOrder[i]<=midOrder[i-1]) return false;
        }
        
        return true;
    }
    
    vector<int> middleOrder(TreeNode *root){
        vector<int> result;
        if(root==NULL) return result;
        if(root->left!=NULL){
            vector<int> l=middleOrder(root->left);
            result.insert(result.begin(), l.begin(), l.end());
        }
        result.push_back(root->val);
        if(root->right!=NULL){
            vector<int> r=middleOrder(root->right);
            result.insert(result.end(), r.begin(), r.end());
        }
        
        return result;
    }
};

int main(){
    TreeNode *root=new TreeNode(10);
    TreeNode *a=new TreeNode(5);
    TreeNode *b=new TreeNode(15);
    TreeNode *c=new TreeNode(6);
    TreeNode *d=new TreeNode(20);
    TreeNode *e=NULL;
    root->left=a;
    root->right=b;
    b->left=c;
    b->right=d;
    
    Solution *solution=new Solution();
    solution->isValidBST(e) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
