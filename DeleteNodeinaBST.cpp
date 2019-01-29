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
    	TreeNode *cur = root, *pre = NULL;
    	while(cur && cur->val != key) {
    		pre = cur;
    		if(cur->val > key) cur = cur->left;
    		else cur = cur->right;
		}
		if(!cur) return root;
		if(cur == root) {
			if(!root->left) return root->right;
			if(!root->right) return root->left;
			cur = root->right;
			while(cur->left) cur = cur->left;
			cur->left = root->left;
			root = root->right;
		}else {
			if(pre->left == cur) {
				if(!cur->right) pre->left = cur->left;
				if(!cur->left) pre->left = cur->right;
				TreeNode *t = cur->right;
				while(t->left) t = t->left;
				t->left = cur->left;
				pre->left = cur->right;
			}else {
				if(!cur->right) pre->right = cur->left;
				if(!cur->left) pre->right = cur->right;
				TreeNode *t = cur->right;
				while(t->left) t = t->left;
				t->left = cur->left;
				pre->right = cur->right;
			}
		}
		
		return root;
    }
};

int main() {
	
	
	
}
