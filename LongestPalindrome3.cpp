#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> m(128);
        int use = 0;
        for(char c : s) {
        	if(++m[c] % 2 == 0) use += 2; 
		}
		
		return use + (use < s.size());
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->longestPalindrome(s);
	
	return 0;
	
}
