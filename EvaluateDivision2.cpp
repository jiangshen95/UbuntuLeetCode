#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
    	
	    unordered_set<string> s;
	    for(auto equation : equations) {
	    	s.insert(equation.first);
	    	s.insert(equation.second);
		}
		
		vector<double> result(queries.size(), -1);
		for(int i = 0; i < queries.size(); i++) {
			
			if(s.find(queries[i].first) != s.end() && s.find(queries[i].second) != s.end()) {
				vector<string> visited;
				result[i] = calcEquation(equations, values, queries[i].first, queries[i].second, visited);
			}
			
		}
		
		return result;
	    
    }
    
    double calcEquation(vector<pair<string, string> > equations, vector<double>& values, string x, string y, vector<string>& visited) {
    	if(x == y) return 1;
    	for(int i = 0; i < equations.size(); i++) {
    		if(x == equations[i].first && y == equations[i].second) return values[i];
    		if(x == equations[i].second && y == equations[i].first) return 1 / values[i];
		}
		
		for(int i = 0; i < equations.size(); i++) {
			if(x == equations[i].first) {
				bool is_ok = true;
				for(int j = 0; j < visited.size(); j++) {
					if(visited[i] == equations[i].second) {
						is_ok = false;
						break;
					}
				}
				if(is_ok) {
					visited.push_back(x);
					double t = calcEquation(equations, values, equations[i].second, y, visited);
					if(t != -1) return t * values[i];
				}
			}else if(x == equations[i].second) {
				bool is_ok = true;
				for(int j = 0; j < visited.size(); j++) {
					if(visited[i] == equations[i].first) {
						is_ok = false;
						break;
					}
				}
				if(is_ok) {
					visited.push_back(x);
					double t = calcEquation(equations, values, equations[i].first, y, visited);
					if(t != -1) return t / values[i];
				}
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
