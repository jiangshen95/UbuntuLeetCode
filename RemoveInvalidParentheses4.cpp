#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
    	unordered_set<string> result;
    	int cnt1 = 0, cnt2 = 0;
    	for(char c : s) {
    		cnt1 += (c == '(');
    		if(cnt1 == 0) cnt2 += (c == ')');
    		else cnt1 -= (c == ')');
		}
    	helper(s, 0, cnt1, cnt2, 0, "", result);
    	return vector<string>(result.begin(), result.end());
    }
    
    void helper(string s, int i, int cnt1, int cnt2, int pair, string path, unordered_set<string>& result) {
    	if(i == s.size()) {
    		if(cnt1 == 0 && cnt2 == 0 && pair == 0) result.insert(path);
    		return;
		}
		
		if(s[i] != '(' && s[i] != ')') helper(s, i + 1, cnt1, cnt2, pair, path + s[i], result);
		else {
			if(s[i] == '(') {
				if(cnt1 > 0) {
					helper(s, i + 1, cnt1 - 1, cnt2, pair, path, result);
				}
				helper(s, i + 1, cnt1, cnt2, pair + 1, path + s[i], result);
			}
			else if(s[i] == ')') {
				if(cnt2 > 0) {
					helper(s, i + 1, cnt1, cnt2 - 1, pair, path, result);
				}
				if(pair > 0) {
					helper(s, i + 1, cnt1, cnt2, pair - 1, path + s[i], result);
				}
			}
		}
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
