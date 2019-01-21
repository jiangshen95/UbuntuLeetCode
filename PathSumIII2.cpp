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
    int pathSum(TreeNode* root, int sum) {
    	if(root == NULL) return 0;
    	vector<TreeNode*> path;
    	return pathSum(root, 0, sum, path);
    }

	int pathSum(TreeNode* root, int curSum, int sum, vector<TreeNode*>& path) {
		if(root == NULL) return 0;
		int count = 0;
		curSum += root->val;
		if(curSum == sum) count++;
		int t = curSum;
		for(int i = 0; i < path.size(); i++) {
			t -= path[i]->val;
			if(t == sum) count++;
		}
		path.push_back(root);
		count += pathSum(root->left, curSum, sum, path) + pathSum(root->right, curSum, sum, path);
		path.pop_back();
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
