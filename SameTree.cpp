#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p!=NULL&&q!=NULL){
            if(p->val!=q->val) return false;
            else{
                return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
            }
        }else{
            if(p==NULL&&q==NULL) return true;
            else return false;
        }
    }
};

int main(){
    TreeNode *p=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *q=new TreeNode(1);
    TreeNode *b=new TreeNode(2);
    
    p->left=a;
    q->right=b;
    
    Solution *solution=new Solution();
    solution->isSameTree(p, q) ? cout<<"True" : cout<<"False";
    
    return 0;
}
