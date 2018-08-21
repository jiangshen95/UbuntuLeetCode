#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> map(26, 0);
        for(int i = 0; i < s.size(); i++) map[s[i] - 'a']++;
        
        int pos = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] < s[pos]) pos = i;
        	if(--map[s[i] - 'a'] == 0) break;
		}
		
		string next = "";
		for(int i = pos + 1; i < s.size(); i++) {
			if(s[i] != s[pos]) next += s[i];
		}
		
		return s.size() == 0 ? "" : s[pos] + removeDuplicateLetters(next);
        
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->removeDuplicateLetters(s);
	
	return 0;
	
}
