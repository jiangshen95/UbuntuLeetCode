#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int> >& heightMap) {
        if(heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        if(m < 3 || n < 3) return 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
        	visited[i][0] = true;
        	visited[i][n - 1] = true;
        	q.push(make_pair(heightMap[i][0], i * n));
        	q.push(make_pair(heightMap[i][n - 1], (i + 1) * n - 1));
		}
		
		for(int i = 1; i < n - 1; i++) {
			visited[0][i] = true;
			visited[m - 1][i] = true;
			q.push(make_pair(heightMap[0][i], i));
			q.push(make_pair(heightMap[m - 1][i], (m - 1) * n + i));
		}
		
		vector<vector<int> > dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
		int result = 0, level = 0;
		while(!q.empty()) {
			pair<int, int> t = q.top();
			q.pop();
			if(t.first > level) level = t.first;
			int x = t.second / n;
			int y = t.second % n;
			cout<<level<<" "<<x<<" "<<y<<endl;
			for(int i = 0; i < 4; i++) {
				int x_ = x + dir[i][0], y_ = y + dir[i][1];
				if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !visited[x_][y_]) {
					if(heightMap[x_][y_] < level) result += level - heightMap[x_][y_];
					visited[x_][y_] = true;
					q.push(make_pair(heightMap[x_][y_], x_ * n + y_));
				}
			}
		}
		
		return result;
        
    }
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<vector<int> > heightMap;
	for(int i = 0; i < m; i++) {
		vector<int> row;
		for(int j = 0; j < n; j++) {
			int h;
			cin>>h;
			row.push_back(h);
		}
		heightMap.push_back(row);
	}
	
	Solution *solution = new Solution();
	cout<<solution->trapRainWater(heightMap);
	
	return 0;
	
}
