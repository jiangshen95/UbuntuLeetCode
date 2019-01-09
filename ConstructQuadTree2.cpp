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
        return build(0, grid.size() - 1, 0, grid.size() - 1, grid);
    }
    
    Node* build(int t, int b, int l, int r, vector<vector<int> >& grid) {
    	if(t > b || l > r) return NULL;
    	int val = grid[t][l];
    	bool isLeaf = true;
    	for(int i = t; i <= b; i++) {
    		for(int j = l; j <= r; j++) {
    			if(grid[i][j] != val) {
    				isLeaf = false;
    				break;
				}
				if(!isLeaf) break;
			}
		}
		if(isLeaf) return new Node(val == 1, isLeaf, NULL, NULL, NULL, NULL);
		return new Node(true, false, build(t, (t + b) / 2, l, (l + r) / 2, grid), 
							build(t, (t + b) / 2, (l + r) / 2 + 1, r, grid), 
							build((t + b) / 2 + 1, b, l, (l + r) / 2, grid), 
							build((t + b) / 2 + 1, b, (l + r) / 2 + 1, r, grid));
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
