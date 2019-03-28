#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
    	
    	vector<vector<int> > dp(m + 1, vector<int>(n + 1));
    	
    	for(string str : strs) {
    		int zeroes = 0, ones = 0;
    		for(char ch : str) ch == '0' ? zeroes++ : ones++;
    		for(int i = m; i >= zeroes; i--) {
    			for(int j = n; j >= ones; j--) {
    				dp[i][j] = max(dp[i][j], dp[i - zeroes][j - ones] + 1);
				}
			}
		}
		
		return dp[m][n];
    	
    }
};

int main() {
	int m, n;
	cin>>n;
	
	vector<string> strs;
	for(int i = 0; i < n; i++) {
		string str;
		cin>>str;
		strs.push_back(str);
	}
	
	cin>>m>>n;
	
	Solution *solution = new Solution();
	cout<<solution->findMaxForm(strs, m, n);
	
	return 0;
}
