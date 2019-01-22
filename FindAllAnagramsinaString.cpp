#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(26, 0), m2(26, 0);
        for(char c : p) m[c - 'a']++;
        
        int count = 0;
        vector<int> result;
        for(int i = 0, j = 0; i < s.size(); i++) {
        	int ch = s[i] - 'a';
        	if(m2[ch] < m[ch]) {
        		count++;
        		m2[ch]++;
			}else {
				if(m[ch] == 0) {
					m2 = vector<int>(26, 0);
					count = 0;
					j = i + 1;
				}else {
					m2[s[j] - 'a']--;
					count--;
					j++;
					i--;
				}
			}
			if(count == p.size()) result.push_back(j);
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
