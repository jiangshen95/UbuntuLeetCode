#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	
    	string data = "";
        
        queue<TreeNode*> nodes;
        
        if(root) {
        	nodes.push(root);
        	data += to_string(root->val) + " ";
		}
        
        while(!nodes.empty()) {
        	
        	TreeNode *node = nodes.front();
        	nodes.pop();
				
			if(node->left) {
				nodes.push(node->left);
				data += to_string(node->left->val) + " ";
			}else {
				data += "n ";
			}
				
			if(node->right) {
				nodes.push(node->right);
				data += to_string(node->right->val) + " ";
			}else {
				data += "n ";
			}
		}
		
		return data;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	
    	TreeNode *root = NULL;
    	queue<TreeNode*> nodes;
    	
    	vector<string> nums;
    	
        
        int last_position =0;
        string num;
        for(int i=0;i<data.size();i++) {
        	if(data[i] == ' ') {
        		num = data.substr(last_position, i - last_position);
        		last_position = i + 1;
        		nums.push_back(num);
			}
		}
		
		for(int i=0;i<nums.size();i++) {
			if(i == 0) {
				root = new TreeNode(stoi(nums[i]));
				nodes.push(root);
			}else {
				TreeNode *cur = nodes.front();
				nodes.pop();
				if(nums[i] != "n") {
					cur->left = new TreeNode(stoi(nums[i]));
					nodes.push(cur->left);
				}
				if(nums[++i] != "n") {
					cur->right = new TreeNode(stoi(nums[i]));
					nodes.push(cur->right);
				}
			}
		}
		
		return root;
    }
    
    void printTree(TreeNode *root) {
    	if(root == NULL) return;
    	cout<<root->val<<" ";
    	printTree(root->left);
    	printTree(root->right);
	}
};

int main() {
	
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(4);
	TreeNode *e = new TreeNode(5);
	TreeNode *f = new TreeNode(6);
	
	a->left = b;
	a->right = c;
	c->left = d;
	c->right = e;
	e->left = f;
	
	Codec *codec = new Codec();
	string data = codec->serialize(a);
	cout<<data<<endl;
	
	codec->printTree(codec->deserialize(data));
	
	
	return 0;
	
}
