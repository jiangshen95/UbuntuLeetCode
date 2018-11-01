#include<iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int indexS = 0, indexT = 0;
        while(indexT < t.size()) {
        	if(s[indexS] == t[indexT]) {
        		indexS++;
        		if(indexS == s.size()) return true;
			}
			indexT++;
		}
		return false;
        
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
