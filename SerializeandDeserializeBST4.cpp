#include<iostream>
#include<sstream>
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
        if(!root) return "";
        ostringstream os;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
        	TreeNode *t = q.front(); q.pop();
        	if(t) {
        		os << t->val << " ";
        		q.push(t->left);
        		q.push(t->right);
			}else {
				os << "# ";
			}
		}
		
		return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if(data.empty()) return NULL;
    	istringstream is(data);
    	queue<TreeNode*> q;
    	string val = "";
    	is >> val;
    	TreeNode *root = new TreeNode(stoi(val)), *cur = root;
    	q.push(cur);
    	while(!q.empty()) {
    		TreeNode *t = q.front(); q.pop();
    		if(!(is >> val)) break;
    		if(val != "#") {
    			cur = new TreeNode(stoi(val));
    			q.push(cur);
    			t->left = cur;
			}
			
			if(!(is >> val)) break;
    		if(val != "#") {
    			cur = new TreeNode(stoi(val));
    			q.push(cur);
    			t->right = cur;
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
