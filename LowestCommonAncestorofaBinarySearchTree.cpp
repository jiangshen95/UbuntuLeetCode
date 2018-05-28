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
        if(isAncestor(root, p) && isAncestor(root, q)){
        	TreeNode *l = lowestCommonAncestor(root->left, p, q);
        	TreeNode *r = lowestCommonAncestor(root->right, p, q);
        	if(l) return l;
        	if(r) return r;
        	return root;
		}else{
			return NULL; 
		}
    }
    
    bool isAncestor(TreeNode *root, TreeNode *p) {
    	if(root == NULL) return false;
    	if(root == p) return true;
    	return isAncestor(root->left, p) || isAncestor(root->right, p);
	}
};

int main(){
	
	TreeNode *a = new TreeNode(6);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(8);
	TreeNode *d = new TreeNode(0);
	TreeNode *e = new TreeNode(4);
	TreeNode *f = new TreeNode(7);
	TreeNode *g = new TreeNode(9);
	TreeNode *h = new TreeNode(3);
	TreeNode *i = new TreeNode(5);
	
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	e->left = h;
	e->right = i;
	
	Solution *solution = new Solution();
	TreeNode *LCA = solution->lowestCommonAncestor(a, b, e);
	
	cout<<LCA->val<<endl;
	
	return 0;
	
}
