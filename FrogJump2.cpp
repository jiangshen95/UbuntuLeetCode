#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
    	
    	vector<unordered_set<int> > dp(stones.size());
    	
    	//dp[0].push_back(0);
    	dp[0].insert(0); 
    	if(stones[1] != 1) return false;
    	//dp[1].push_back(1);
    	dp[1].insert(1);
    	
    	for(int i = 2; i < stones.size(); i++) {
    		for(int j = i - 1; j > 0; j--) {
    			for(int k : dp[j]) {
    				if(stones[j] + k - 1 == stones[i]) dp[i].insert(k - 1);
    				else if(stones[j] + k == stones[i]) dp[i].insert(k);
    				else if(stones[j] + k + 1 == stones[i]) dp[i].insert(k + 1);
				}
				if(stones[j] + j + 1 < stones[i]) break;
			}
		}
		
		return !dp.back().empty();
    	
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> stones;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		stones.push_back(num);
	}
	
	Solution *solution = new Solution();
	solution->canCross(stones) ? cout<<"true" : cout<<"false";
	
	return 0;
}
