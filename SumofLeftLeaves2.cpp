#include<iostream>
#include<queue>

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
        
        queue<TreeNode*> q;
        if(root) q.push(root);
        
        int result = 0;
        while(!q.empty()) {
        	TreeNode *cur = q.front();q.pop();
//        	if(cur->left && cur->left->left == NULL && cur->left->right == NULL) result += cur->left->val;
//        	if(cur->left) q.push(cur->left);
//        	if(cur->right) q.push(cur->right);
			if(cur->left) {
				if(cur->left->left == NULL && cur->left->right == NULL) result += cur->left->val;
				else q.push(cur->left);
			}
			if(cur->right) {
				if(cur->right->left || cur->right->right) q.push(cur->right);
			}
		}
        
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
