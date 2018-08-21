#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> map(26, 0);
        for(int i = 0; i < s.size(); i++) map[s[i] - 'a']++;
        
        stack<char> st;
        vector<int> visited(26, false);
        
        for(int i = 0; i < s.size(); i++) {
        	map[s[i] - 'a']--;
        	if(visited[s[i] - 'a']) continue;
        	while(!st.empty() && s[i] < st.top() && map[st.top() - 'a'] != 0) {
        		visited[st.top() - 'a'] = false;
        		st.pop();
			}
			st.push(s[i]);
			visited[s[i] - 'a'] = true;
		}
        
        string result = "";
        while(!st.empty()) {
        	result = st.top() + result;
        	st.pop();
		}
		
		return result;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->removeDuplicateLetters(s);
	
	return 0;
	
}
