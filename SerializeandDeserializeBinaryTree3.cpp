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
    	
    	if(root == NULL) return "[]";
    	
    	string data = "";
    	
        buildString(root, data);
        data[data.size() - 1] = ']';
        data = "[" + data;
        
        return data;
    }
    
    void buildString(TreeNode *root, string& data) {
    	if(root == NULL) data += "null,";
    	else {
    		data += to_string(root->val) + ",";
    		buildString(root->left, data);
    		buildString(root->right, data);
		}
	}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	
    	if(data.size() <= 2) return NULL;
    	
    	queue<string> nodes;
    	
        
        int last_position =0;
        string num;
        for(int i=1;i<data.size();i++) {
        	if(data[i] == ',' || data[i] == ']') {
        		num = data.substr(last_position + 1, i - last_position - 1);
        		last_position = i;
				nodes.push(num);
			}
		}
		
		return buildTree(nodes);
    }
    
    TreeNode* buildTree(queue<string>& nodes) {
    	string node = nodes.front();
    	nodes.pop();
    	
    	if(node == "null") {
    		return NULL;
		}else {
			TreeNode *cur = new TreeNode(stoi(node));
			cur->left = buildTree(nodes);
			cur->right = buildTree(nodes);
			return cur;
		}
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
