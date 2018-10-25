#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> m(26, 0);
        for(char c: s) {
        	m[c - 'a']++;
		}
		for(char c: t) {
			if(m[c - 'a']-- == 0) return c;
		}
		
		return 0;
    }
};

int main() {
	
	string s, t;
	cin>>s>>t;
	
	Solution *solution = new Solution();
	cout<<solution->findTheDifference(s, t);
	
	return 0;
	
}
