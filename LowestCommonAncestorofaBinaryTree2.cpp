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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        return !l ? r : !r ? l : root;
    }
};

int main(){
	
	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(5);
	TreeNode *c = new TreeNode(1);
	TreeNode *d = new TreeNode(6);
	TreeNode *e = new TreeNode(2);
	TreeNode *f = new TreeNode(0);
	TreeNode *g = new TreeNode(8);
	TreeNode *h = new TreeNode(7);
	TreeNode *i = new TreeNode(4);
	
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	e->left = h;
	e->right = i;
	
	Solution *solution = new Solution();
	TreeNode *LCA = solution->lowestCommonAncestor(a, b, c);
	
	cout<<LCA->val<<endl;
	
	return 0;
	
}
