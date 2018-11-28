#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> m(52, 0);
        for(char c : s) {
        	if(c >= 'a' && c <= 'z') m[c - 'a']++;
        	else m[c - 'A' + 26]++;
		}
		int count = 0;
		for(int n : m) {
			if(n % 2) count++; 
		}
		
		return count > 0 ? s.size() - count + 1 : s.size();
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->longestPalindrome(s);
	
	return 0;
	
}
