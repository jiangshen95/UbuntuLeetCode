#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        
        int num = 0;
        stack<int> stk;
        stack<string> s_stk;
        string temp = "";
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i] - '0';
        	else if(s[i] == '[') {
        		stk.push(num);
        		s_stk.push(temp);
        		num = 0;
        		temp = "";
			}
			else if(s[i] == ']') {
				int n = stk.top();
				stk.pop();
				string instr = s_stk.top();
				s_stk.pop();
				for(int j = 0; j < n; j++) {
					instr += temp;
				} 
				temp = instr;
			}
			else {
				temp += s[i];
			}
		}
		
		return temp;
        
    }
};

int main() {
	string s;
	cin>>s;
	Solution *solution = new Solution();
	cout<<solution->decodeString(s)<<endl;
	return 0;
}
