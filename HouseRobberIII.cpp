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
    int rob(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int sum1 = 0;
        int sum2 = 0;
        
        sum1 += root->val;
        if(root->left) {
        	sum1 += rob(root->left->left) + rob(root->left->right);
		}
		if(root->right) {
			sum1 += rob(root->right->left) + rob(root->right->right); 
		}
		
		sum2 += rob(root->left) + rob(root->right);
        
        return max(sum1, sum2);
        
    }
    
};

int main() {
	
//	TreeNode *a = new TreeNode(3);
//	TreeNode *b = new TreeNode(2); 
//	TreeNode *c = new TreeNode(3); 
//	TreeNode *d = new TreeNode(3); 
//	TreeNode *e = new TreeNode(1); 
//	
//	a->left = b;
//	a->right = c;
//	b->right = d;
//	c->right = e;

	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(4);
	TreeNode *c = new TreeNode(5);
	TreeNode *d = new TreeNode(1);
	TreeNode *e = new TreeNode(3);
	TreeNode *f = new TreeNode(1);
	
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->right = f;
	
	Solution *solution = new Solution();
	cout<<solution->rob(a);
	
	return 0;
	
}
