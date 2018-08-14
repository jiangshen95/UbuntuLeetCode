#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
    	
    	if(n <= 1) return vector<int>{0}; 
    	
        vector<vector<int> > tree(n);
        for(int i = 0; i < edges.size(); i++) {
			
			tree[edges[i].first].push_back(edges[i].second);
        	tree[edges[i].second].push_back(edges[i].first);
        	
		}
		
		vector<int> d1(n), d2(n), pre(n);
		bfs(tree, n, 0, d1, pre);
		int u = 0;
		for(int i = 0; i < n; i++) {
			if(d1[i] > d1[u]) u = i;
		}
		bfs(tree, n, u, d2, pre);
		int v = 0;
		for(int i = 0; i < n; i++) {
			if(d2[i] > d2[v]) v = i;
		}
		
		vector<int> list;
		while(v != -1) {
			list.push_back(v);
			v = pre[v];
		}
		
		if(list.size() % 2 == 1) return vector<int>{list[list.size() / 2]};
		else return vector<int>{list[list.size() / 2 - 1], list[list.size() / 2]}; 
		
		
    }
    
	void bfs(vector<vector<int> > tree, int n, int start, vector<int>& dist, vector<int>& pre) {
		vector<bool> visited(n);
		queue<int> q;
		q.push(start);
		dist[start] = 0;
		visited[start] = true;
		pre[start] = -1;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto v : tree[u]) {
				if(!visited[v]) {
					dist[v] = dist[u] + 1;
					visited[v] = true;
					q.push(v);
					pre[v] = u;
				}
			}
		}
	}
    
};

int main() {
	
	int n;
	cin>>n;
	
	int m;
	cin>>m;
	
	vector<pair<int, int> > edges;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin>>x>>y;
		edges.push_back(make_pair(x, y));
	}
	
	Solution *solution = new Solution();
	vector<int> result = solution->findMinHeightTrees(n, edges);
	
	for(int i = 0; i < result.size(); i++) {
		cout<<result[i]<<"  ";
	}
	
	return 0;
	
}
