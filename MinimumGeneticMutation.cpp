#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_map<string, unordered_set<string> > tree;
        for(int i = 0; i < bank.size(); i++) {
        	if(canTranslate(start, bank[i])) tree[start].insert(bank[i]);
        	if(canTranslate(end, bank[i])) tree[end].insert(bank[i]);
        	for(int j = i + 1; j < bank.size(); j++) {
        		if(canTranslate(bank[i], bank[j])) {
        			tree[bank[i]].insert(bank[j]);
        			tree[bank[j]].insert(bank[i]);
				}
			}
		}
		
		unordered_set<string> visited;
		return getMinMutation(start, end, tree, visited);
        
    }
    
    int getMinMutation(string s, string end, unordered_map<string, unordered_set<string> >& tree, unordered_set<string> visited) {
    	if(s == end) return 0;
		if(tree.find(s) == tree.end()) return -1;
    	
    	visited.insert(s);
    	int step = INT_MAX;
    	for(auto next : tree[s]) {
    		if(visited.find(next) == visited.end()) {
    			cout<<next<<endl;
    			int t = getMinMutation(next, end, tree, visited);
    			if(t != -1) step = min(step, t);
			}
		}
		
		return step == INT_MAX ? -1 : step + 1;
	}
    
    bool canTranslate(string s1, string s2) {
    	int count = 0;
    	for(int i = 0; i < s1.size(); i++) {
    		if(s1[i] != s2[i]) {
    			count++;
    			if(count > 1) return false;
			}
		}
		return count == 1;
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
