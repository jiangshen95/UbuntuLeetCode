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
    vector<string> binaryTreePaths(TreeNode* root) {
    	
    	vector<string> paths;
    	
    	if(root == NULL) return paths;
    	
    	if(root->left == NULL && root->right == NULL) {
    		paths.push_back(to_string(root->val));
    		return paths;
		}
		
		for(auto path : binaryTreePaths(root->left)) {
			paths.push_back(to_string(root->val) + "->" + path);
		}
		
		for(auto path : binaryTreePaths(root->right)) {
			paths.push_back(to_string(root->val) + "->" + path);
		}
		
		return paths;
    	
    }
    
};

int main() {
	
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(5);
	
	a->left = b;
	a->right = c;
	b->right = d;
	
	Solution *solution = new Solution();
	vector<string> result = solution->binaryTreePaths(a);
	
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
	
	return 0;
}
