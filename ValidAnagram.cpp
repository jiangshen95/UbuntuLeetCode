#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    	
    	if(s.length() != t.length()) return false;
        
        vector<int> map(26, 0);
        
        for(int i = 0;i < s.length();i++) {
        	map[s[i] - 'a'] ++;
		}
		
		for(int i = 0;i < t.length();i++) {
			if(map[t[i] - 'a'] == 0) return false;
			map[t[i] - 'a'] --;
		}
		
		return true;
        
    }
};

int main() {
	
	string s, t;
	cin>>s;
	cin>>t;
	
	Solution *solution = new Solution();
	solution->isAnagram(s, t) ? cout<<"True" : cout<<"False";
	
	return 0;
	
}
