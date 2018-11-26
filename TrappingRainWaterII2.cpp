#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int> >& heightMap) {
        if(heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        if(m < 3 || n < 3) return 0;
        
        vector<vector<int> > dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        
        int start = m * n;
        vector<vector<pair<int, int> > > g(m * n + 1);
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(i == 0 || i == m - 1 || j == 0 || j == n - 1) g[start].push_back(make_pair(i * n + j, 0));
        		for(int k = 0; k < 4; k++) {
        			int x = i + dir[k][0], y = j + dir[k][1];
        			if(x >= 0 && x < m && y >= 0 && y < n) g[i * n + j].push_back(make_pair(x * n + y, heightMap[i][j]));
				}
			}
		}
		
		vector<int> dist = dijkstra(g, start);
		int result = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(dist[i * n + j] > heightMap[i][j]) result += dist[i * n + j] - heightMap[i][j];
			}
		}
		
		return result;
    }
    
    vector<int> dijkstra(vector<vector<pair<int, int> > >& g, int start) {
    	vector<int> dist(g.size(), INT_MAX / 2);
    	dist[start] = 0;
    	
    	struct cmp {
    		bool operator()(pair<int, int> a, pair<int, int> b) {
    			if(a.second == b.second && a.first == b.first) return false;
    			else return a.second == b.second ? a.first < b.first : a.second < b.second;
			}
		};
		
		set<pair<int, int>, cmp> tree;
		tree.insert(make_pair(start, 0));
		
		while(!tree.empty()) {
			pair<int, int> t = *tree.begin();
			tree.erase(tree.begin());
			int u = t.first, d = t.second;
			for(auto e : g[u]) {
				int v = e.first, w = e.second;
				if(max(d, w) < dist[v]) {
					tree.erase(make_pair(v, dist[v]));
					dist[v] = max(d, w);
					tree.insert(make_pair(v, dist[v]));
				}
			}
		}
		
		return dist;
    	
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
