#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        for(char c : s) {
        	if(st.find(c) != st.end()) st.erase(c);
        	else st.insert(c);
		}
		
		return st.empty() ? s.size() : s.size() - st.size() + 1;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->longestPalindrome(s);
	
	return 0;
	
}
