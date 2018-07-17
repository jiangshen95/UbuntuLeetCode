/*
*  Time Limit Exceeded
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
        
        vector<TreeNode*> nodes;
        vector<int> position;
        
        nodes.push_back(root);
        position.push_back(1);
        
        int last_position = 0;
        int num = 1;
        while(!nodes.empty()) {
        	int size = nodes.size();
        	for(int i=0;i<size;i++) {
        		if(last_position > 0 && position[i] - last_position > 1) {
        			for(int j=0;j<position[i] - last_position - 1;j++) {
        				data += "null,";
					}
				}
				
				data += to_string(nodes[i]->val) + ",";
				last_position = position[i];
				
				if(nodes[i]->left) {
					nodes.push_back(nodes[i]->left);
					position.push_back(position[i] * 2);
				}
				
				if(nodes[i]->right) {
					nodes.push_back(nodes[i]->right);
					position.push_back(position[i] * 2 + 1);
				}
			}
			
			num *= 2;
			
			nodes.erase(nodes.begin(), nodes.begin() + size);
			position.erase(position.begin(), position.begin() + size);
		}
		
		num = num - 1;
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
    	vector<TreeNode*> nodes;
    	vector<int> position;
    	
        
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
        			nodes.push_back(root);
        			position.push_back(count);
				} else{
					
					if(num != "null") {
					
						while(count > position.front() * 2 + 1) {
							nodes.erase(nodes.begin());
							position.erase(position.begin());
						}
						
						TreeNode *cur = nodes.front();
						if(count == position.front() * 2) {
							cur->left = new TreeNode(stoi(num));
							nodes.push_back(cur->left);
							position.push_back(count);
						}else if(count == position.front() * 2 + 1) {
							cur->right = new TreeNode(stoi(num));
							nodes.push_back(cur->right);
							position.push_back(count);
							
							nodes.erase(nodes.begin());
							position.erase(position.begin());
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
