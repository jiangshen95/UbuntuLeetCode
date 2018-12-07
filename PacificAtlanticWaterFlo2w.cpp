#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
    	
    	vector<pair<int, int> > result;
    	if(matrix.empty()) return result;
        
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<bool> > pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        queue<pair<int, int> > q1, q2; 
        for(int i = 0; i < m; i++) {
        	q1.push(make_pair(i, 0));
        	q2.push(make_pair(i, n - 1));
		}
		
		for(int i = 0; i < n; i++) {
			q1.push(make_pair(0, i));
			q2.push(make_pair(m - 1, i));
		}
		
		bfs(matrix, m, n, q1, pacific);
		bfs(matrix, m, n, q2, atlantic);
		
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++)
				if(pacific[i][j] && atlantic[i][j]) result.push_back(make_pair(i, j));
		}
		
		return result;
        
    }
    
    void bfs(vector<vector<int> >& matrix, int m, int n, queue<pair<int, int> >& q, vector<vector<bool> >& place) {
    	
    	vector<vector<int> > dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    	while(!q.empty()) {
    		pair<int, int> t = q.front(); q.pop();
    		int x = t.first, y = t.second;
    		place[x][y] = true;
    		for(int i = 0; i < 4; i++) {
    			int x_ = x + dir[i][0], y_ = y + dir[i][1];
    			if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && matrix[x_][y_] >= matrix[x][y] && !place[x_][y_]) q.push(make_pair(x_, y_));
			}
		}
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
