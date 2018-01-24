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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> line;
        
        vector<TreeNode*> stack;
        TreeNode *cur=root, *pre=NULL;
        int SUM=0;
        
        while(cur || !stack.empty()){
            while(cur){
                stack.push_back(cur);
                SUM+=cur->val;
                line.push_back(cur->val);
                cur=cur->left;
            }
            
            cur=stack.back();
            
            if(cur->right!=NULL && cur->right!=pre){
                cur=cur->right;
                continue;
            }
            
            if(cur->left==NULL && cur->right==NULL && SUM==sum){
                result.push_back(line);
            }
            
            pre=cur;
            stack.pop_back();
            line.pop_back();
            SUM-=cur->val;
            cur=NULL;
            
        }
        
        return result;
    }
    
    void pathSum(vector<vector<int> >& result, vector<int>& line, TreeNode *root, int sum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL && sum==root->val){
            line.push_back(root->val);
            result.push_back(line);
            line.pop_back();
        }else{
            line.push_back(root->val);
            pathSum(result, line, root->left, sum-root->val);
            pathSum(result, line, root->right, sum-root->val);
            line.pop_back();
        }
    }
};

int main(){
    
    TreeNode *root=new TreeNode(5);
    TreeNode *a=new TreeNode(4);
    TreeNode *b=new TreeNode(8);
    TreeNode *c=new TreeNode(11);
    TreeNode *d=new TreeNode(13);
    TreeNode *e=new TreeNode(4);
    TreeNode *f=new TreeNode(7);
    TreeNode *g=new TreeNode(2);
    TreeNode *h=new TreeNode(1);
    TreeNode *k=new TreeNode(5);
    
    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->left=k;
    e->right=h;
    
    int sum;
    cin>>sum;
    
    Solution *solution=new Solution();
    vector<vector<int> > result=solution->pathSum(root, sum);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
    
}

