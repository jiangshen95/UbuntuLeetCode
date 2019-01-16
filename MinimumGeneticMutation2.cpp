#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        if(bank.empty()) return -1;
        bank.push_back(start);
        
        int n = bank.size();
        queue<int> q{{n - 1}};
        vector<vector<int> > dist(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
        	for(int j = i + 1; j < n; j++) dist[i][j] = dist[j][i] = countDiff(bank[i], bank[j]);
		}
        int step = 0;
        unordered_set<int> visited;
        while(!q.empty()) {
        	int size = q.size();
        	step++;
        	for(int i = 0; i < size; i++) {
        		int t = q.front();q.pop();
        		visited.insert(t);
        		for(int j = 0; j < n; j++) {
        			if(dist[j][t] != 1 || visited.find(j) != visited.end()) continue;
					if(bank[j] == end) return step;
					q.push(j);
				}
			}
		}
		
		return -1;
        
    }
    
    int countDiff(string s1, string s2) {
    	int count = 0;
    	for(int i = 0; i < s1.size(); i++)
    		if(s1[i] != s2[i]) count++;
    	return count;
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
