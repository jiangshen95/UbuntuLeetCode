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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int in_begin, int in_end, vector<int>& postorder, int post_begin, int post_end){
        
        if(post_begin>post_end) return NULL;
        
        TreeNode *root=new TreeNode(postorder[post_end]);
        
        int where;
        
        for(int i=in_begin;i<=in_end;i++){
            if(inorder[i]==postorder[post_end]){
                where=i;
                break;
            }
        }
        
        root->left=buildTree(inorder, in_begin, where-1, postorder, post_begin, post_begin+where-in_begin-1);
        root->right=buildTree(inorder, where+1, in_end, postorder, post_begin+where-in_begin, post_end-1);
        
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
    
    vector<int> inorder;
    vector<int> postorder;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        inorder.push_back(num);
    }
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        postorder.push_back(num);
    }
    
    Solution *solution=new Solution();
    TreeNode *root=solution->buildTree(inorder, postorder);
    
    solution->printTree(root);
    
    return 0;
}
