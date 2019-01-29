#include<iostream>
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
    	if(root == NULL) return "|";
    	queue<TreeNode*> nodes;
    	nodes.push(root);
    	string result = "";
    	while(!nodes.empty()) {
    		int size = nodes.size();
    		for(int i = 0; i < size; i++) {
    			TreeNode *node = nodes.front();
    			nodes.pop();
    			if(node) {
    				result += to_string(node->val) + "|";
    				nodes.push(node->left);
    				nodes.push(node->right);
				}else {
					result += "|";
				}
			}
		}
		return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if(data == "|") return NULL;
    	queue<TreeNode*> nodes;
    	vector<TreeNode*> children;
    	TreeNode *root = NULL;
    	int num = 0;
    	for(int i = 0; i < data.size(); i++) {
    		if(data[i] == '|') {
    			TreeNode *node = NULL;
    			if(data[i - 1] != '|') {
    				node = new TreeNode(num);
    				num = 0;
				}
				if(nodes.empty()) {
					nodes.push(node);
					root = node;
				}else {
					children.push_back(node);
					if(children.size() == 2) {
						while(!(nodes.front())) nodes.pop();
						nodes.front()->left = children[0];
						nodes.front()->right = children[1];
						nodes.push(children[0]);
						nodes.push(children[1]);
						nodes.pop();
						children.clear();
					}
				}
			}else {
				num = num * 10 + data[i] - '0';
			}
		}
    	return root;
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
