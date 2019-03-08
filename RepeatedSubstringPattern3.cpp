#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
    	string ss = s + s;
    	return ss.substr(1, ss.size() - 2).find(s) != -1;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	solution->repeatedSubstringPattern(s) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
