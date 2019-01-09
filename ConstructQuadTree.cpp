#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;
	
	Node() {}
	
	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
public:
    Node* construct(vector<vector<int> >& grid) {
        Node *node = new Node(true, false, NULL, NULL, NULL, NULL);
        int n = grid.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) sum += grid[i][j];
		}
		if(sum == 0) {
			node->isLeaf = true;
			node->val = false;
		}else if(sum == n * n) {
			node->isLeaf = true;
			node->val = true;
		}else {
			node->isLeaf = false;
			vector<vector<int> > top_left(n / 2, vector<int>(n / 2, 0)), top_right(n / 2, vector<int>(n / 2, 0));
			vector<vector<int> > bottom_left(n / 2, vector<int>(n / 2, 0)), bottom_right(n / 2, vector<int>(n / 2, 0));
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(i < n / 2 && j < n / 2) top_left[i][j] = grid[i][j];
					else if(i < n / 2) top_right[i][j - n / 2] = grid[i][j];
					else if(i >= n / 2 && j < n / 2) bottom_left[i - n / 2][j] = grid[i][j];
					else bottom_right[i - n / 2][j - n / 2] = grid[i][j];
				}
			} 
			node->topLeft = construct(top_left);
			node->topRight = construct(top_right);
			node->bottomLeft = construct(bottom_left);
			node->bottomRight = construct(bottom_right);
		}
		
		return node;
    }
};

int main() {
	
	vector<vector<int> > grid(8, vector<int>(8, 1));
	
	for(int i = 4; i < 8; i++) {
		grid[0][i] = 0;
		grid[1][i] = 0;
	}
	
	for(int i = 4; i < 8; i++) {
		for(int j = 4; j < 8; j++) {
			grid[i][j] = 0;
		}
	}
	
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) cout<<grid[i][j]<<" ";
		cout<<endl;
	}
	
	Solution *solution = new Solution();
	solution->construct(grid);
	
	return 0;
}
