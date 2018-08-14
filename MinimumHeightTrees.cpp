/*
** Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<vector<int> > tree(n);
        vector<int> deeps(n);
        for(int i = 0; i < edges.size(); i++) {
        	tree[edges[i].first].push_back(edges[i].second);
        	tree[edges[i].second].push_back(edges[i].first);
		}
		
		int min_deep;
		for(int i = 0; i < n; i++) {
			int deep = getDeep(tree, i, i);
			if(i == 0 || deep < min_deep) min_deep = deep;
			deeps[i] = deep;
		}
		
		vector<int> result;
		for(int i = 0; i < n; i++){
			if(deeps[i] == min_deep) result.push_back(i);
		}
		
		return result;
		
    }
    
    int getDeep(vector<vector<int> > tree, int i, int last) {
    	int deep = 0;
    	for(auto node : tree[i]) {
    		if(node != last) {
    			int t = getDeep(tree, node, i);
    			if(t > deep) deep = t;
			}
		}
		
		return deep + 1;
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
