#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
    	
    	vector<pair<int, int> > result;
    	if(matrix.empty()) return result;
        
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<bool> > pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
        	dfs(matrix, m, n, i, 0, pacific, INT_MIN);
        	dfs(matrix, m, n, i, n - 1, atlantic, INT_MIN);
		}
		
		for(int i = 0; i < n; i++) {
			dfs(matrix, m, n, 0, i, pacific, INT_MIN);
			dfs(matrix, m, n, m - 1, i, atlantic, INT_MIN);
		}
		
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++)
				if(pacific[i][j] && atlantic[i][j]) result.push_back(make_pair(i, j));
		}
		
		return result;
        
    }
    
    void dfs(vector<vector<int> >& matrix, int m, int n, int x, int y, vector<vector<bool> >& visited, int pre) {
    	if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || matrix[x][y] < pre) return;
    	visited[x][y] = true;
    	dfs(matrix, m, n, x - 1, y, visited, matrix[x][y]);
    	dfs(matrix, m, n, x + 1, y, visited, matrix[x][y]);
    	dfs(matrix, m, n, x, y - 1, visited, matrix[x][y]);
    	dfs(matrix, m, n, x, y + 1, visited, matrix[x][y]);
	}
    
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<vector<int> > matrix;
	for(int i = 0; i < m; i++) {
		vector<int> row;
		for(int j = 0; j < n; j++) {
			int num;
			cin>>num;
			row.push_back(num);
		}
		matrix.push_back(row);
	}
	
	Solution *solution = new Solution();
	vector<pair<int, int> > result = solution->pacificAtlantic(matrix);
	
	for(int i = 0; i < result.size(); i++) {
		cout<<result[i].first<<"  "<<result[i].second<<endl;
	}
	
	return 0;
	
}
