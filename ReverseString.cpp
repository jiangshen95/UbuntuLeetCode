#include<iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
        	char ch = s[l];
        	s[l] = s[r];
        	s[r] = ch;
        	l++;
        	r--;
		}
		return s;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	s = solution->reverseString(s);
	
	cout<<s;
	
	return 0;
	
}
