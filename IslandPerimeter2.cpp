#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
    	int len = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(grid[i][j] == 1) {
        			len += 4;
        			if(i > 0 && grid[i - 1][j] == 1) len -= 2;
        			if(j > 0 && grid[i][j - 1] == 1) len -= 2;
				}
        		
			}
		}
		return len;
    }
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<vector<int> > grid;
	for(int i = 0; i < m; i++) {
		vector<int> row;
		for(int j = 0; j < n; j++) {
			int num;
			cin>>num;
			row.push_back(num);
		}
		grid.push_back(row);
	}
	
	Solution *solution = new Solution();
	cout<<solution->islandPerimeter(grid);
	
	return 0;
	
} 
