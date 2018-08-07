#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
    	vector<string> result;
    	helper(s, 0, 0, {'(', ')'}, result);
    	return result;
    }
    
    void helper(string s, int last_i, int last_j, vector<char> p, vector<string>& result) {
    	int cnt = 0;
    	for(int i = last_i;i < s.size();i++) {
    		if(s[i] == p[0]) cnt++;
    		else if(s[i] == p[1]) cnt--;
    		if(cnt >= 0) continue;
    		for(int j = last_j;j <= i;j++) {
    			if(s[j] == p[1] && (j == last_j || s[j] != s[j - 1])) {
    				helper(s.substr(0, j) + s.substr(j + 1), i, j, p, result);
				}
			}
			return;
		}
		
		string rev = string(s.rbegin(), s.rend());
		if(p[0] == '(') helper(rev, 0, 0, {')', '('}, result);
		else result.push_back(rev);
	}
    
};

int main() {
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	vector<string> result = solution->removeInvalidParentheses(s);
	
	for(int i=0;i<result.size();i++) cout<<result[i]<<endl;
	
	return 0;
}
