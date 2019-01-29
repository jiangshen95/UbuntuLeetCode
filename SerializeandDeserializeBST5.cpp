#include<iostream>
#include<sstream>
#include<algorithm> 
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
        ostringstream os;
        serialize(root, os);
        return os.str();
    }
    
    void serialize(TreeNode* root, ostringstream& os) {
    	if(!root) return;
    	os<<root->val<<" ";
    	serialize(root->left, os);
    	serialize(root->right, os);
	}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	istringstream is(data);
    	queue<int> q;
    	string val = "";
    	while(is >> val) {
    		cout<<val<<"  ";
    		q.push(stoi(val));
		}
    	return deserialize(q, INT_MIN, INT_MAX);
    }
    
    TreeNode* deserialize(queue<int>& q, int min_num, int max_num) {
    	if(q.empty()) return NULL;
    	int num = q.front();
    	if(num > max_num || num < min_num)	return NULL;
		q.pop();
    	TreeNode *node = new TreeNode(num);
    	node->left = deserialize(q, min_num, num);
    	node->right = deserialize(q, num, max_num);
    	return node;
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
