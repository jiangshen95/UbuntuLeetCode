#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
    	int i = 1, j = 0, n = s.size();
    	vector<int> dp(n + 1);
		while(i < n) {
			if(s[i] == s[j]) dp[++i] = ++j;
			else if(j == 0) i++;
			else j = dp[j];
		} 
		for(int t : dp) cout<<t<<" ";
		return dp[n] && (dp[n] % (n - dp[n]) == 0);
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	solution->repeatedSubstringPattern(s) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
