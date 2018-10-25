#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> m(26, 0);
        char ch = 0;
        ch ^= t.back();
        for(int i = 0; i < s.size(); i++) {
        	ch ^= s[i];
        	ch ^= t[i];
		}
		return ch;
    }
};

int main() {
	
	string s, t;
	cin>>s>>t;
	
	Solution *solution = new Solution();
	cout<<solution->findTheDifference(s, t);
	
	return 0;
	
}
