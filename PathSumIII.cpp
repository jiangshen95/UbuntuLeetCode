#include<iostream>
#include<unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
    	if(root == NULL) return 0;
    	return sumUp(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

	int sumUp(TreeNode* root, int sum) {
		if(!root) return 0;
		return (sum == root->val) + sumUp(root->left, sum - root->val) + sumUp(root->right, sum - root->val);
	}
};

int main() {
	
	TreeNode *a = new TreeNode(10);
	TreeNode *b = new TreeNode(5);
	TreeNode *c = new TreeNode(-3);
	TreeNode *d = new TreeNode(3);
	TreeNode *e = new TreeNode(2);
	TreeNode *f = new TreeNode(11);
	TreeNode *g = new TreeNode(3);
	TreeNode *h = new TreeNode(-2);
	TreeNode *i = new TreeNode(1);
	
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->right = f;
	d->left = g;
	d->right = h;
	e->right = i;
	
	Solution *solution = new Solution();
	cout<<solution->pathSum(a, 8);
	
	return 0; 
	
} 
