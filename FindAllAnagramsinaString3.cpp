#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(26, 0);
        
        for(char ch : p) m[ch - 'a']++;
        
        int left = 0, right = 0, cnt = p.size();
        vector<int> result;
        while(right < s.size()) {
        	if(m[s[right++] - 'a']-- >= 1) cnt--;
        	if(cnt == 0) result.push_back(left);
        	if(right - left == p.size() && m[s[left++] - 'a']++ >= 0) cnt++;
		}
		return result;
    }
};

int main() {
	
	string s, p;
	cin>>s>>p;
	
	Solution *solution = new Solution();
	vector<int> result = solution->findAnagrams(s, p);
	
	for(int r : result) cout<<r<<" ";
	
	return 0;
	
} 
