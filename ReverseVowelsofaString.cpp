#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<bool> vowels(26, false);
        vowels['a' - 'a'] = true;
        vowels['e' - 'a'] = true;
        vowels['i' - 'a'] = true;
        vowels['o' - 'a'] = true;
        vowels['u' - 'a'] = true;
        
        int l = 0, r = s.size() - 1;
        while(l < r) {
        	while(l < r && !(s[l] >= 'a' && s[l] <= 'z' && vowels[s[l] - 'a']) && !(s[l] >= 'A' && s[l] <= 'Z' && vowels[s[l] - 'A'])) l++;
        	while(l < r && !(s[r] >= 'a' && s[r] <= 'z' && vowels[s[r] - 'a']) && !(s[r] >= 'A' && s[r] <= 'Z' && vowels[s[r] - 'A'])) r--;
        	if(l < r){
        		char t = s[l];
	        	s[l] = s[r];
	        	s[r] = t;
	        	l++;
	        	r--;
			}
		}
		
		return s;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	s = solution->reverseVowels(s);
	
	cout<<s;
	
	return 0;
	
}
