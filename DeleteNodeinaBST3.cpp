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
    	if(root->val == key) {
    		if(!root->right) return root->left;
    		TreeNode *cur = root->right;
    		while(cur->left) cur = cur->left;
    		swap(cur->val, root->val);
		}
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
    }
};

int main() {
	
	
	
}
