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
    	
    	TreeNode *cur = root;
    	string path = "";
    	vector<TreeNode*> stack;
    	vector<string> path_stack;
    	
    	while(!stack.empty() || cur) {
    		while(cur) {
    			path += to_string(cur->val) + "->";
    			stack.push_back(cur);
    			path_stack.push_back(path);
    			cur = cur->left;
			}
			
			cur = stack.back();
			stack.pop_back();
			
			path = path_stack.back();
			path_stack.pop_back();
			
			//cout<<path<<endl;
			
			if(cur->right == NULL && cur->left == NULL) {
				path.erase(path.end() - 1);
				path.erase(path.end() - 1);
				result.push_back(path);
			}
			
			cur = cur->right;
		}
		
		return result;
    	
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
