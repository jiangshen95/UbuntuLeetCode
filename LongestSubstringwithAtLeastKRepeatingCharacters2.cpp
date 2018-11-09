#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.size(), max_index = 0, result = 0;
        vector<int> m(26, 0);
        
        for(char ch : s) m[ch - 'a']++;
        
        bool ok = true;
        for(int i = 0; i < n; i++) {
        	if(m[s[i] - 'a'] < k) {
        		result = max(result, longestSubstring(s.substr(max_index, i - max_index), k));
        		ok = false;
        		max_index = i + 1;
			}
		}
		
		return ok ? n : max(result, longestSubstring(s.substr(max_index, n - max_index), k)); 
        
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
