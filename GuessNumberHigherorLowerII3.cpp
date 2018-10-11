#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = 2; i <= n; i++) {
        	
        	int k0 = i - 1;
        	deque<pair<int, int> > v;
        	for(int j = i - 1; j > 0; j--) {
        		
        		while(dp[j][k0 - 1] > dp[k0 + 1][i]) {
        			if(!v.empty() && v.front().second == k0) v.pop_front();
        			k0--;
				}
				
				int vn = j + dp[j + 1][i];
				while(!v.empty() && v.back().first > vn) v.pop_back();
				v.emplace_back(vn, j);
				int u1 = k0 + 1 + dp[j][k0];
				int u2 = v.front().first;
				dp[j][i] = min(u1, u2);
        		
			}
		}
		
		return dp[1][n];
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->getMoneyAmount(n);
	
	return 0;
	
} 
