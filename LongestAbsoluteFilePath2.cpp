#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        
        int pre = 0;
        bool is_file = false;
        vector<string> stack;
        int deep = 0;
        int len = 0, max_len = 0;
        for(int i = 0;i < input.size(); i++) {
        	if(input[i] == '.') {
        		is_file = true;
			}else if(input[i] == '\n' || input[i] == '\t' || i == input.size() - 1) {
				if(input[i - 1] == '\n' || input[i - 1] == '\t') {
					deep++;
					pre = i + 1;
					continue;
				}
				
				if(i == input.size() - 1) i++;
				string s = input.substr(pre, i - pre);
				cout<<"s: "<<s<<"  deep: "<<deep<<endl;
				
				while(deep < stack.size()) {
					len -= stack.back().size() + 1;
					stack.pop_back();
				}
				if(is_file) {
					if(len + s.size() > max_len) max_len = len + s.size();
				}else {
					len += s.size() + 1;
					stack.push_back(s);
					//cout<<"len: "<<len<<"  s: "<<s<<endl;
				}
				deep = 0;
				is_file = false;
				pre = i + 1;
			}
		}
        
        return max_len;
    }
};

int main() {
	
	string input;
	cin>>input;
	
	Solution *solution = new Solution();
	cout<<solution->lengthLongestPath(input);
	
	return 0;
	
}
