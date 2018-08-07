#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
    	vector<string> result;
    	int cnt1 = 0, cnt2 = 0;
    	for(char c : s) {
    		cnt1 += (c == '(');
    		if(cnt1 == 0) cnt2 += (c == ')');
    		else cnt1 -= (c == ')');
		}
		
		helper(s, 0, cnt1, cnt2, result);
		
		return result;
    }
    
    void helper(string s, int start, int cnt1, int cnt2, vector<string>& result) {
    	if(cnt1 == 0 && cnt2 == 0) {
    		if(isValidParenthese(s)) result.push_back(s);
    		return;
		}
		
		for(int i = start;i < s.size(); i++) {
			if(i != start && s[i] == s[i - 1]) continue;
			if(cnt1 > 0 && s[i] == '(') {
//				string temp = s;
//				temp.erase(temp.begin() + i);
//				helper(temp, i, cnt1 - 1, cnt2, result);
				helper(s.substr(0, i) + s.substr(i + 1), i, cnt1 - 1, cnt2, result);
			}
			if(cnt2 > 0 && s[i] == ')') {
//				string temp = s;
//				temp.erase(temp.begin() + i);
//				helper(temp, i, cnt1, cnt2 - 1, result);
				helper(s.substr(0, i) + s.substr(i + 1), i, cnt1, cnt2 - 1, result);
			}
		}
	}
    
    bool isValidParenthese(string s) {
    	vector<char> stack;
    	for(int i=0;i<s.size();i++) {
    		if(s[i] != '(' && s[i] != ')') continue;
    		if(stack.empty()) stack.push_back(s[i]);
    		else{
    			if(s[i] == '(') stack.push_back(s[i]);
    			else if(s[i] == ')' && stack.back() == '(') stack.pop_back();
    			else if(s[i] == ')' && stack.back() == ')') return false;
			}
		}
		
		return stack.empty();
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
