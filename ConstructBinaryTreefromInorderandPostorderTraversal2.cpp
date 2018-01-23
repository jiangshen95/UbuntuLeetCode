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
        
        int i=postorder.size()-1, j=inorder.size()-1;
        vector<TreeNode*> stack;
        
        TreeNode *root, *t;
        
        bool isLeft=false;
        
        root=new TreeNode(postorder[i]);
        t=root;
        stack.push_back(root);
        i--;
        
        while(i>=0){
            
            if(!stack.empty()&&stack.back()->val==inorder[j]){
                t=stack.back();
                stack.pop_back();
                j--;
                isLeft=true;
            }else{
                if(isLeft){
                    t->left=new TreeNode(postorder[i]);
                    t=t->left;
                    stack.push_back(t);
                    isLeft=false;
                    i--;
                }else{
                    t->right=new TreeNode(postorder[i]);
                    t=t->right;
                    stack.push_back(t);
                    i--;
                }
            }
        }
        
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
