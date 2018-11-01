#include<iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i = 0;
        for(char c : s) {
        	while(i < t.size() && t[i] != c) i++;
        	if(i >= t.size()) return false;
        	i++;
		}
		
		return true;
        
    }
};

int main() {
	
	string s, t;
	cin>>s;
	cin>>t;
	
	Solution *solution = new Solution();
	solution->isSubsequence(s, t) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
