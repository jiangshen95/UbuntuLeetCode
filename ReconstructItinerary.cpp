#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        
        unordered_map<string, multiset<string> > m;
        
        for(auto a : tickets) {
        	m[a.first].insert(a.second);
		}
		
		vector<string> result;
		
		dfs(m, "JFK", result);
		
		return vector<string>(result.rbegin(), result.rend());
        
    }
    
    void dfs(unordered_map<string, multiset<string> >& m, string node, vector<string>& result) {
    	
    	while(!m[node].empty()) {
    		string t = *m[node].begin();
    		m[node].erase(m[node].begin());
    		dfs(m, t, result);
		}
		
		result.push_back(node);
    	
	}
    
};

int main() {
	
	int n;
	cin>>n;
	
	vector<pair<string, string> > tickets;
	for(int i = 0; i < n; i++) {
		string from, to;
		cin>>from>>to;
		tickets.push_back(make_pair(from, to));
	}
	
	Solution *solution = new Solution();
	vector<string> result = solution->findItinerary(tickets);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
	
}
