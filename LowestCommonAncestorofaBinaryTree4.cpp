#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Frame {
	TreeNode *node;
	Frame *parent;
	vector<TreeNode*> subs;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Frame answer;
        stack<Frame> stack;
        stack.push({root, &answer});
        while (!stack.empty()){
        	Frame *top = &stack.top(), *parent = top->parent;
        	TreeNode *node = top->node;
        	if(!node || node == p || node == q){
        		parent->subs.push_back(node);
        		stack.pop();
			}else if(top->subs.empty()) {
				stack.push({node->left, top});
				stack.push({node->right, top});
			}else {
				TreeNode *left = top->subs[0], *right = top->subs[1];
				parent->subs.push_back(!left ? right : !right ? left : node);
				stack.pop();
			}
		}
		
		return answer.subs[0];
    }
};

int main(){
	
	TreeNode *a = new TreeNode(3);
	TreeNode *b = new TreeNode(5);
	TreeNode *c = new TreeNode(1);
	TreeNode *d = new TreeNode(6);
	TreeNode *e = new TreeNode(2);
	TreeNode *f = new TreeNode(0);
	TreeNode *g = new TreeNode(8);
	TreeNode *h = new TreeNode(7);
	TreeNode *i = new TreeNode(4);
	
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	e->left = h;
	e->right = i;
	
	Solution *solution = new Solution();
	TreeNode *LCA = solution->lowestCommonAncestor(a, b, c);
	
	cout<<LCA->val<<endl;
	
	return 0;
	
}
