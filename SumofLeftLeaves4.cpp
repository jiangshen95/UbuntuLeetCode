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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root, bool isLeft) {
    	if(!root) return 0;
        if(root->left == NULL && root->right == NULL) return isLeft ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};

int main() {
	
	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(9);
	TreeNode *c = new TreeNode(20);
	TreeNode *d = new TreeNode(15);
	TreeNode *e = new TreeNode(7);
	
	a->left = b;
	a->right = c;
	c->left = d;
	c->right = e;
	
	Solution *solution = new Solution();
	cout<<solution->sumOfLeftLeaves(a)<<endl;
	
	return 0;
	
}
