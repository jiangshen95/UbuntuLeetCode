#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
private:
	vector<vector<int> > tree;
	int n;
	vector<int> height1;
	vector<int> height2;
	vector<int> dp;
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
    	
    	if(n <= 1) return vector<int>{0}; 
    	
    	this->n = n;
    	tree = vector<vector<int> >(n);
    	height1 = vector<int>(n);
    	height2 = vector<int>(n);
    	dp = vector<int>(n);
    	
        for(int i = 0; i < edges.size(); i++) {
			
			tree[edges[i].first].push_back(edges[i].second);
        	tree[edges[i].second].push_back(edges[i].first);
        	
		}
		
		dfs(0, -1);
		dfs(0, -1, 0);
		
		int min_deep;
		vector<int> result;
		for(int i = 0; i < n; i++) {
			if(i == 0 || dp[i] < min_deep) {
				min_deep = dp[i];
				result.clear();
				result.push_back(i);
			}else if(dp[i] == min_deep) {
				result.push_back(i);
			}
		}
		
		return result;
    }
    
    void dfs(int u, int parent) {
    	
    	height1[u] = height2[u] = INT_MIN;
    	for(auto v : tree[u]) {
    		if(v != parent) {
    			dfs(v, u);
    			int temp = height1[v] + 1;
    			if(temp > height1[u]) {
    				height2[u] = height1[u];
    				height1[u] = temp;
				}else if(temp > height2[u]) {
					height2[u] = temp;
				}
			}
		}
		height1[u] = max(height1[u], 0);
	}
	
	void dfs(int u, int parent, int acc) {
		dp[u] = max(height1[u], acc);
		for(auto v : tree[u]) {
			if(v != parent) {
				int newAcc = max(acc + 1, (height1[v] + 1 == height1[u] ? height2[u] : height1[u]) + 1);
				dfs(v, u, newAcc);
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
