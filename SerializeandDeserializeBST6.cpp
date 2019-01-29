#include<iostream>
#include<sstream>
#include<algorithm> 
#include<queue>
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
        s.push(root);
        while(!s.empty()) {
        	TreeNode *t = s.top(); s.pop();
        	os << t->val << " ";
        	if(t->right) s.push(t->right);
        	if(t->left) s.push(t->left);
		}
		return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if(data.empty()) return NULL;
    	istringstream is(data);
    	queue<int> q;
    	string val = "";
    	while(is >> val) {
    		cout<<val<<"  ";
    		q.push(stoi(val));
		}
    	return deserialize(q);
    }
    
    TreeNode* deserialize(queue<int> q) {
    	if(q.empty()) return NULL;
    	int num = q.front(); q.pop();
    	TreeNode *root = new TreeNode(num);
    	queue<int> smaller;
    	while(!q.empty() && q.front() < root->val) {
    		smaller.push(q.front());
    		q.pop();
		}
		root->left = deserialize(smaller);
		root->right = deserialize(q);
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
