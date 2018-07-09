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
    	
    	vector<string> result;
    	getPath(root, "", result);
    	
    	return result;
    	
    }
    
    void getPath(TreeNode *root, string path, vector<string>& result) {
    	
    	if(root == NULL) return;
    	
    	if(root->left == NULL && root->right == NULL) {
    		path += to_string(root->val);
    		result.push_back(path);
		}
		
		path += to_string(root->val) + "->";
		
		getPath(root->left, path, result);
		getPath(root->right, path, result);
    	
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
