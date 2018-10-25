#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        
        int pre = 0;
        bool is_file = false;
        unordered_map<int, int> path;
        path[0] = 0;
        int deep = 0;
        int max_len = 0;
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
				
				if(is_file) {
					if(path[deep] + s.size() > max_len) max_len = path[deep] + s.size();
				}else {
					path[deep + 1] = path[deep] + s.size() + 1;
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
