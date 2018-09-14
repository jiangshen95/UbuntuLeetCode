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
    int rob(TreeNode* root) {
        
        unordered_map<TreeNode*, int> m;
        
        return robSub(root, m);
        
    }
    
    int robSub(TreeNode* root, unordered_map<TreeNode*, int>& m) {
    	
    	if(root == NULL) return 0;
    	if(m[root]) return m[root];
        
    	int sum1 = 0;
        int sum2 = 0;
        
        sum1 += root->val;
        if(root->left) {
        	sum1 += robSub(root->left->left, m) + robSub(root->left->right, m);
		}
		if(root->right) {
			sum1 += robSub(root->right->left, m) + robSub(root->right->right, m); 
		}
		
		sum2 += robSub(root->left, m) + robSub(root->right, m);
		
		int sum = max(sum1, sum2);
		
		m[root] = sum;
        
        return sum;
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
