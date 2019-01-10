#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;
	
	Node() {}
	
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
    vector<vector<int> > levelOrder(Node* root) {
        vector<vector<int> > result;
        if(root == NULL) return result;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
        	int size = q.size();
        	vector<int> values;
        	for(int i = 0; i < size; i++) {
        		Node *temp = q.front();
        		q.pop();
        		values.push_back(temp->val);
        		for(auto n : temp->children) q.push(n);
			}
			result.push_back(values);
		}
		
        return result;
    }
};

int main() {
	
	Node *a = new Node();
	Node *b = new Node();
	Node *c = new Node();
	Node *d = new Node();
	Node *e = new Node();
	Node *f = new Node();
	
	a->val = 1;
	b->val = 3;
	c->val = 2;
	d->val = 4;
	e->val = 5;
	f->val = 6;
	
	a->children.push_back(b);
	a->children.push_back(c);
	a->children.push_back(d);
	
	b->children.push_back(e);
	b->children.push_back(f);
	
	Solution *solution = new Solution();
	vector<vector<int> > result = solution->levelOrder(a);
	
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) cout<<result[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}
