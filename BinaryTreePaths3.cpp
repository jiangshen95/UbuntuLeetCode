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
    	
    	if(!root) return result;
    	
    	vector<TreeNode*> nodes;
    	vector<string> paths;
    	
    	nodes.push_back(root);
    	paths.push_back("");
		
		while(!nodes.empty()) {
			int size = nodes.size();
			for(int i=0;i<size;i++) {
				if(nodes[i]->left == NULL && nodes[i]->right == NULL){
					result.push_back(paths[i] + to_string(nodes[i]->val));
				}
				if(nodes[i]->left) {
					nodes.push_back(nodes[i]->left);
					paths.push_back(paths[i] + to_string(nodes[i]->val) + "->");
				}
				if(nodes[i]->right) {
					nodes.push_back(nodes[i]->right);
					paths.push_back(paths[i] + to_string(nodes[i]->val) + "->");
				}
			}
			nodes.erase(nodes.begin(), nodes.begin() + size);
			paths.erase(paths.begin(), paths.begin() + size);
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
