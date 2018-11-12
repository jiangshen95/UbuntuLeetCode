#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
	    
        unordered_map<string, vector<pair<string, double> > > m;
        for(int i = 0; i < equations.size(); i++) {       	
        	m[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
        	m[equations[i].second].push_back(make_pair(equations[i].first, 1 / values[i]));
		}
		
		vector<double> result(queries.size(), -1);
		for(int i = 0; i < queries.size(); i++) {
			if(m.find(queries[i].first) != m.end() && m.find(queries[i].second) != m.end()) {
				if(queries[i].first == queries[i].second) {
					result[i] = 1;
					continue;
				}
				
				queue<pair<string, double> > q;
				unordered_set<string> visited;
				bool had_find = false;
				q.push(make_pair(queries[i].first, 1));
				while(!q.empty() && !had_find) {
					pair<string, double> x = q.front(); q.pop();
					for(auto item : m[x.first]) {
						if(item.first == queries[i].second) {
							had_find = true;
							result[i] = x.second * item.second;
							break;
						}else {
							if(visited.find(item.first) == visited.end()) {
								q.push(make_pair(item.first, x.second * item.second));
								visited.insert(item.first);
							}
						}
					}
				}
			}
		}
        
        return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<pair<string, string> > equations;
	for(int i = 0; i < n; i++) {
		string s1, s2;
		cin>>s1>>s2;
		equations.push_back(make_pair(s1, s2));
	}
	
	vector<double> values;
	for(int i = 0; i < n; i++) {
		double v;
		cin>>v;
		values.push_back(v);
	}
	
	cin>>n;
	vector<pair<string, string> > queries;
	for(int i = 0; i < n; i++) {
		string s1, s2;
		cin>>s1>>s2;
		queries.push_back(make_pair(s1, s2));
	}
	
	Solution *solution = new Solution();
	vector<double> result = solution->calcEquation(equations, values, queries);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
	
}
