#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
	    
        unordered_map<string, vector<pair<string, double> > > m;
        for(int i = 0; i < equations.size(); i++) {       	
        	m[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
        	m[equations[i].second].push_back(make_pair(equations[i].first, 1 / values[i]));
		}
		
		for(auto &x : m) {
			cout<<x.first<<": ";
			for(auto y : x.second) {
				cout<<y.first<<" ";
			}
			cout<<endl;
		}
		
		
		vector<double> result(queries.size(), -1);
		for(int i = 0; i < queries.size(); i++) {
			if(m.find(queries[i].first) != m.end() && m.find(queries[i].second) != m.end()) {
				result[i] = calcEquation(m, "", queries[i].first, queries[i].second);
			}
		}
        
        return result;
    }
    
    double calcEquation(unordered_map<string, vector<pair<string, double> > > m, string pre, string start, string end) {
    	for(auto x : m[start]) {
    		if(x.first == end) return x.second;
		}
		
		for(auto x : m[start]) {
			if(x.first != pre) {
				double t = calcEquation(m, start, x.first, end);
				if(t != -1) return x.second * t;
			}
		}
		
		return -1;
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
