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
		vector<string> stack{"JFK"};
		
		while(!stack.empty()) {
			
			string s = stack.back();
			if(m[s].empty()) {
				result.insert(result.begin(), s);
				stack.pop_back();
			}else {
				stack.push_back(*m[s].begin());
				m[s].erase(m[s].begin());
			}
			
		}
		
		return result;
        
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
