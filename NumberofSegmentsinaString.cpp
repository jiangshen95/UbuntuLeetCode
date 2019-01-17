#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        int count = 0;
        
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == ' ' && i > 0 && s[i - 1] != ' ') count++;
		}
		
		if(s.back() != ' ') count++;
		
		return count;
        
    }
};

int main() {
	
	string s;
	getline(cin, s);
	
	Solution *solution = new Solution();
	cout<<solution->countSegments(s);
	
	return 0;
	
} 
