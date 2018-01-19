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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode *buildTree(vector<int>& preorder, int pre_begin, int pre_end, vector<int>& inorder, int in_begin, int in_end){
        
        if(pre_begin>pre_end) return NULL;
        
        TreeNode *root=new TreeNode(preorder[pre_begin]);
        
        int where;
        
        for(int i=in_begin;i<=in_end;i++){
            if(inorder[i]==preorder[pre_begin]){
                where=i;
                break;
            }
        }
        
        root->left=buildTree(preorder, pre_begin+1, pre_begin+where-in_begin, inorder, in_begin, where-1);
        root->right=buildTree(preorder, pre_begin+where-in_begin+1, pre_end, inorder, where+1, in_end);
        
        return root;
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
    
    vector<int> preorder;
    vector<int> inorder;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        preorder.push_back(num);
    }
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        inorder.push_back(num);
    }
    
    Solution *solution=new Solution();
    TreeNode *root=solution->buildTree(preorder, inorder);
    
    solution->printTree(root);
    
    return 0;
}
