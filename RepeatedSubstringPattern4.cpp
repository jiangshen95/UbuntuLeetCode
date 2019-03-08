#include<iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
    	int n = s.size();
        for(int i = 1; i <= n / 2; i++) {
        	if(n % i == 0) {
        		string t = s.substr(i);
        		t += s.substr(0, i);
				if(t == s) return true;
			}
		}
		return false;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	solution->repeatedSubstringPattern(s) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
