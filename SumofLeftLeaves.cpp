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
        if(root == NULL) return 0;
        int result = 0;
		if(root->left && root->left->left == NULL && root->left->right == NULL) result += root->left->val;
		result +=  sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return result;
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
