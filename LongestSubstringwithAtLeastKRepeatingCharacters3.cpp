#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int res = 0;
        
        for(int h = 1; h <= 26; h++) {
        	vector<int> m(26, 0);
        	int i = 0, j = 0;
        	int unique = 0;
        	int noLessThenK = 0;
        	while(j < s.size()) {
        		if(unique <= h) {
        			int t = s[j] - 'a';
        			if(m[t] == 0) unique++;
        			m[t]++;
        			if(m[t] == k) noLessThenK++;
        			j++;
				}else {
					int t = s[i] - 'a';
					if(m[t] == k) noLessThenK--;
					if(m[t] == 1) unique--;
					m[t]--;
					i++;
				}
				if(unique == h && noLessThenK == h) res = max(res, j - i);
			}
		}
		
		return res;
        
    }
};

int main() {
	
	string s;
	cin>>s;
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	cout<<solution->longestSubstring(s, k)<<endl;
	
	return 0;
}
