#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
    	unordered_set<string> set;
    	queue<string> q;
    	vector<string> result;
    	q.push(s);
    	set.insert(s);
    	
    	while(!q.empty()) {
    		string t = q.front();
    		q.pop();
    		if(!result.empty() && t.size() < result.back().size()) break;
    		if(isValidParenthese(t)) result.push_back(t);
    		else {
    			for(int i = 0;i < t.size();i++) {
    				string temp = t;
    				temp.erase(temp.begin() + i);
    				if(set.find(temp) == set.end()) {
    					set.insert(temp);
    					q.push(temp);
					}
				}
			}
		}
		return result;
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
