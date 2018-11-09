#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        return longestSubstring(s, 0, s.size() - 1, k);
        
    }
    
    int longestSubstring(string s, int start, int end, int k) {
    	
    	vector<int> m(26, 0);
    	for(int i = start; i <= end; i++) m[s[i] - 'a']++;
    	
    	int res = 0;
    	for(int j = start; j <= end; j++) {
    		while(j <= end && m[s[j] - 'a'] < k) j++;
    		if(j > end) break;
    		int r = j;
    		while(r <= end && m[s[r] - 'a'] >= k) r++;
    		if(r > end && j == start) return end - start + 1;
    		res = max(res, longestSubstring(s, j, r - 1, k));
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
