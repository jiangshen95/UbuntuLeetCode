#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(26, 0), m2(26, 0);
        
        for(int i = 0; i < p.size(); i++) {
        	m[p[i] - 'a']++;
        	m2[s[i] - 'a']++;
		}
		
		vector<int> result;
		
		if(m == m2) result.push_back(0);
		for(int i = p.size(); i < s.size(); i++) {
			m2[s[i] - 'a']++;
			m2[s[i - p.size()] - 'a']--;
			if(m == m2) result.push_back(i - p.size() + 1);
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
