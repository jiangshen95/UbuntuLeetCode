#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        vector<int> m(26, 0);
        
        for(char ch : s) m[ch - 'a']++;
        
        for(int i = 0; i < s.size(); i++) {
        	if(m[s[i] - 'a'] < k) {
        		int left = longestSubstring(s.substr(0, i), k);
        		int right = longestSubstring(s.substr(i + 1), k);
        		return max(left, right);
			}
		}
		
		return s.size();
        
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
