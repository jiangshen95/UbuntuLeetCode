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
    TreeNode* deleteNode(TreeNode* root, int key) {
    	if(!root) return NULL;
    	if(root->val > key) root->left = deleteNode(root->left, key);
		else if(root->val < key) root->right = deleteNode(root->right, key);
		else {
			if(!root->right) return root->left;
			if(!root->left) return root->right;
			TreeNode *cur = root->right;
			while(cur->left) cur = cur->left;
//			root->val = cur->val;
//			root->right = deleteNode(root->right, root->val);
			cur->left = root->left;
			return root->right;
		}
		return root;
    }
};

int main() {
	
	
	
}
