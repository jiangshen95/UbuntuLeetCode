#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    	
    	if(envelopes.empty()) return 0;
    	
    	sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    		if(a.first == b.first) return a.second > b.second;
    		return a.first < b.first;
		});
		
		vector<int> dp;
		
		for(int i = 0; i < envelopes.size(); i++) {
			
			int l = 0, r = dp.size(), t = envelopes[i].second;
			while(l < r) {
				int mid = l + (r - l) / 2;
				if(dp[mid] < t) l = mid + 1;
				else r = mid;
			}
			if(r >= dp.size()) dp.push_back(t);
			else dp[r] = t;
			
		}
        
        return dp.size();
    	
        
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<pair<int, int> > envelops;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin>>a>>b;
		envelops.push_back(make_pair(a, b));
	}
	
	Solution *solution = new Solution();
	cout<<solution->maxEnvelopes(envelops);
	
	return 0;
	
}
