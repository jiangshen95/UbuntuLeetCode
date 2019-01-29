#include<iostream>
#include<sstream>
#include<algorithm> 
#include<vector>
#include<stack>

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
    	if(!root) return "";
        ostringstream os;
        stack<TreeNode*> s;
        while(!s.empty() || root) {
        	if(root) {
        		os << root->val <<" ";
        		s.push(root);
        		root = root->left;
			}else {
				root = s.top(); s.pop();
				root = root->right;
			}
		}
		return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if(data.empty()) return NULL;
    	istringstream is(data);
    	vector<int> nodes;
    	string val = "";
    	while(is >> val) {
    		cout<<val<<"  ";
    		nodes.push_back(stoi(val));
		}
    	return deserialize(nodes);
    }
    
    TreeNode* deserialize(vector<int> nodes) {
    	TreeNode *root = new TreeNode(nodes[0]);
    	TreeNode *cur = root;
    	stack<TreeNode*> s;
    	for(int i = 1; i < nodes.size(); i++) {
    		if(nodes[i] < cur->val) {
    			cur->left = new TreeNode(nodes[i]);
    			s.push(cur);
    			cur = cur->left;
			}else {
				while(!s.empty() && s.top()->val < nodes[i]) {
					cur = s.top();
					s.pop();
				}
				cur->right = new TreeNode(nodes[i]);
				cur = cur->right;
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
