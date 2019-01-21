#include<iostream>
#include<unordered_map>

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
    	unordered_map<int, int> m;
		m[0] = 1; 
    	return pathSum(root, 0, sum, m);
    }

	int pathSum(TreeNode* root, int curSum, int sum, unordered_map<int, int>& m) {
		if(root == NULL) return 0;
		int count = 0;
		curSum += root->val;
		count += m[curSum - sum];
		m[curSum]++;
		count += pathSum(root->left, curSum, sum, m) + pathSum(root->right, curSum, sum, m);
		m[curSum]--;
		return count;
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
