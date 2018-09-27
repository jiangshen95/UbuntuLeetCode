#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    	
    	if(envelopes.empty()) return 0;
        
    	vector<int> dp(envelopes.size(), 1);
    	
    	qsort(envelopes, 0, envelopes.size() - 1);
    	
    	int max_en = 1;
    	for(int i = 1; i < envelopes.size(); i++) {
    		for(int j = 0; j < i; j++) {
    			if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
    				dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			max_en = max(max_en, dp[i]);
		}
		
		return max_en;
    	
        
    }
    
    void qsort(vector<pair<int, int> >& envelopes, int l, int r) {
    	if(l >= r) return;
    	int i = l, j = r;
    	pair<int, int> v = envelopes[l];
    	while(i < j) {
    		while(i < j && envelopes[j].first >= v.first) j--;
    		envelopes[i] = envelopes[j];
    		while(i < j && envelopes[i].first <= v.first) i++;
    		envelopes[j] = envelopes[i];
		}
		envelopes[i] = v;
		qsort(envelopes, l, i - 1);
		qsort(envelopes, i + 1, r);
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
