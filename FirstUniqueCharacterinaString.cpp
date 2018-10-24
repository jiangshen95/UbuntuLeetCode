#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> m(26, 0);
        
        for(char c : s) m[c - 'a']++;
        
        for(int i = 0; i < s.size(); i++)
        	if(m[s[i] - 'a'] == 1) return i;
        return -1;
        
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->firstUniqChar(s);
	
	return 0;
	
}
