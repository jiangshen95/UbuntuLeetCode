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
		
		queue<int> q;
		for(int i = 0; i < n; i++)
			if(tree[i].size() == 1) q.push(i);
			
		while(n > 2) {
			int size = q.size();
			n -= size;
			for(int i = 0; i < size; i++) {
				int t = q.front();
				q.pop();
				int next = tree[t][0];
				for(int i = 0; i < tree[next].size(); i++) {
					if(tree[next][i] == t) {
						tree[next].erase(tree[next].begin() + i);
						if(tree[next].size() == 1) q.push(next);
						break;
					}
				}
			}
		}
		
		vector<int> result;
		while(!q.empty()) {
			result.push_back(q.front());
			q.pop();
		}
		
		return result;
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
