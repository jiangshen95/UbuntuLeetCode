#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        if(bank.empty()) return -1;
        queue<string> q{{start}};
        unordered_set<string> s(bank.begin(), bank.end());
        unordered_set<string> visited;
        vector<char> gens{'A', 'G', 'C', 'T'};
        
        int step = 0;
        while(!q.empty()) {
        	int size = q.size();
        	for(int i = 0; i < size; i++) {
        		string t = q.front();q.pop();
        		visited.insert(t);
        		if(t == end) return step;
        		for(int j = 0; j < t.size(); j++) {
        			char old = t[j];
        			for(char gen : gens)
        				if(gen != old) {
        					t[j] = gen;
        					if(s.find(t) != s.end() && visited.find(t) == visited.end()) q.push(t);
						}
					t[j] = old;
				}
			}
			step++;
		}
        
        return -1;
    }
};

int main() {
	
	string start, end;
	cin>>start;
	cin>>end;
	
	vector<string> bank;
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++) {
		string s;
		cin>>s;
		bank.push_back(s);
	}
	
	Solution *solution = new Solution();
	cout<<solution->minMutation(start, end, bank);
	
	return 0;
	
}
