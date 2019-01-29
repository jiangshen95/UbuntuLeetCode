#include<iostream>

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
        if(root == NULL) return "NULL|";
        return to_string(root->val) + "|" + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	string s = data;
    	return helper(s);
    }
    
    TreeNode* helper(string& data) {
    	int num = 0;
        for(int i = 0; i < data.size(); i++) {
        	if(data[i] >= '0' && data[i] <= '9') num = num * 10 + data[i] - '0';
        	if(data[i] == '|') {
        		TreeNode *node = NULL;
        		if(data[i - 1] >= '0' && data[i - 1] <= '9') {
        			node = new TreeNode(num);
				}
				data = data.substr(i + 1);
				if(node) {
					cout<<node->val<<"  ";
					node->left = helper(data);
					node->right = helper(data);
				}
				return node;
			}
		}
		return NULL;
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
	b->left = d;
	b->right = e;
	c->left = f;
	
	Codec *codec = new Codec();
	string data = codec->serialize(a);
	cout<<data<<endl;
	codec->deserialize(data);
	
	return 0;
	
}
