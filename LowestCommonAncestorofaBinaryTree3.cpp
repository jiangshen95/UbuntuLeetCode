#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> stack;
        stack.push_back(root);
        unordered_map<TreeNode*, TreeNode*> map;
        map[root] = NULL;
        while(map.find(p) == map.end() || map.find(q) == map.end()){
        	TreeNode *cur = stack.front();
			stack.erase(stack.begin());
			if(cur->left) {
				map[cur->left] = cur;
				stack.push_back(cur->left);
			}
			if(cur->right){
				map[cur->right] = cur;
				stack.push_back(cur->right);
			}
		}
		
		unordered_set<TreeNode*> ancestors;
		while(p) {
			ancestors.insert(p);
			p = map[p];
		}
		
		while(ancestors.find(q) == ancestors.end()){
			q = map[q];
		}
		
		return q;
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
