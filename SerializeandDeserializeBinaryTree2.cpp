/*
*  Memory Limit Exceeded
*/
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
        
        queue<TreeNode*> nodes;
        queue<int> position;
        
        nodes.push(root);
        position.push(1);
        
        int last_position = 0;
        int num = 1;
        while(!nodes.empty()) {
        	
        	TreeNode *node = nodes.front();
        	nodes.pop();
        	int cur_position = position.front();
        	position.pop();
        	
        	if(last_position > 0 && cur_position - last_position > 1) {
        		for(int j=0;j<cur_position - last_position - 1;j++) {
        			data += "null,";
				}
			}
				
			data += to_string(node->val) + ",";
			last_position = cur_position;
				
			if(node->left) {
				nodes.push(node->left);
				position.push(cur_position * 2);
			}
				
			if(node->right) {
				nodes.push(node->right);
				position.push(cur_position * 2 + 1);
			}
			
			if(node->left || node->right) {
				num *= 2;
			}
			
		}
		
		num = num * 2 - 1;
		for(int i=last_position+1;i<=num;i++) data += "null,";
		
		data[data.size() - 1] = ']';
		data = '[' + data;
		
		//cout<<data<<endl;
		
		return data;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	
    	if(data.size() <= 2) return NULL;
    	
    	TreeNode *root = NULL;
    	queue<TreeNode*> nodes;
    	queue<int> position;
    	
        
        int last_position =0;
        int count = 0;
        string num;
        for(int i=1;i<data.size();i++) {
        	if(data[i] == ',' || data[i] == ']') {
        		num = data.substr(last_position + 1, i - last_position - 1);
        		last_position = i;
        		count ++;
        		if(count == 1) {
        			root = new TreeNode(stoi(num));
        			nodes.push(root);
        			position.push(count);
				} else{
					
					if(num != "null") {
					
						while(count > position.front() * 2 + 1) {
							nodes.pop();
							position.pop();
						}
						
						TreeNode *cur = nodes.front();
						if(count == position.front() * 2) {
							cur->left = new TreeNode(stoi(num));
							nodes.push(cur->left);
							position.push(count);
						}else if(count == position.front() * 2 + 1) {
							cur->right = new TreeNode(stoi(num));
							nodes.push(cur->right);
							position.push(count);
							
							nodes.pop();
							position.pop();
						}
						
					}
					
				}
			}
		}
		
		return root;
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
