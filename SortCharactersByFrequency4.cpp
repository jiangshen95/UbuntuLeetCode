#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char, int> m;
        for(char c : s) {
        	m[c]++;
		}
		
		vector<string> chars(s.size() + 1);
		for(auto it : m) {
			chars[it.second].append(it.second, it.first);
		}
		
		string result = "";
		for(int i = chars.size() - 1; i >= 0; i--) {
			if(!chars[i].empty()) result.append(chars[i]);
		}
		
		return result;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->frequencySort(s);
	
	return 0;
	
}
