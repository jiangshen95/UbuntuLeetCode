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
    int rob(TreeNode* root) {
        
        vector<int> result = robSub(root);
        return max(result[0], result[1]);
    }
    
    vector<int> robSub(TreeNode* root) {
    	if(root == NULL) return vector<int>(2, 0);
    	
    	vector<int> left = robSub(root->left);
    	vector<int> right = robSub(root->right);
    	
    	vector<int> res(2, 0);
    	res[0] = max(left[0], left[1]) + max(right[0], right[1]); 
    	res[1] = root->val + left[0] + right[0];
    	
    	return res;
    	
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
