#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        vector<bool> explored(bank.size(), false);
        
        return minMutation(explored, start, end, bank);
        
    }
    
    int minMutation(vector<bool>& explored, string start, string end, vector<string>& bank) {
    	if(start == end) return 0;
    	
    	int step = bank.size() + 1;
    	for(int i = 0; i < bank.size(); i++) {
    		if(!explored[i] && canTranslate(start, bank[i])) {
    			explored[i] = true;
    			int t = minMutation(explored, bank[i], end, bank);
    			if(t != -1 && t < step) step = t;
    			explored[i] = false;
			}
		}
		
		return step == bank.size() + 1 ? -1 : step + 1;
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
