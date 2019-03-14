#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
    	int len = 0, m = grid.size(), n = grid[0].size();
    	vector<vector<int> > dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(grid[i][j] == 1) {
        			for(int k = 0; k < 4; k++) {
        				if(i + dir[k][0] < 0 || i + dir[k][0] >= m || j + dir[k][1] < 0 || j + dir[k][1] >= n || grid[i + dir[k][0]][j + dir[k][1]] == 0 ) len++;
					} 
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
