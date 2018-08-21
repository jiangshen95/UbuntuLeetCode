#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> map(26, 0);
        for(int i = 0; i < s.size(); i++) map[s[i] - 'a']++;
        
        string result = "";
        
        for(int i = 0; i < s.size(); i++) {
        	if(map[s[i] - 'a'] == 1) result += s[i];
        	else if(map[s[i] - 'a'] == -1) continue;
			else {
				int j = i + 1;
				vector<int> temp(26, 0);
				for(; j < s.size(); j++) {
					if(s[j] > s[i]) {
						temp[s[j] - 'a']++;
						if(temp[s[j] - 'a'] == map[s[j] - 'a']) {
							result += s[i];
							map[s[i] - 'a'] = -1;
							break;
						}
					}else if(s[j] < s[i] && map[s[j] - 'a'] != -1) {
						map[s[i] - 'a']--;
						break;
					}
				}
				if(j == s.size()) {
					result += s[i];
					map[s[i] - 'a'] = -1;
				}
			}
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
