#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char, int> m;
        for(char c : s) {
        	m[c]++;
		}
		
		priority_queue<pair<int, char> > q;
		for(auto it : m) q.push(make_pair(it.second, it.first));
		
		string result;
		while(!q.empty()) {
			pair<int, char> t = q.top(); q.pop();
			result.append(t.first, t.second);
		} 
		
		return result;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->frequencySort(s);
	
	return 0;
	
}
