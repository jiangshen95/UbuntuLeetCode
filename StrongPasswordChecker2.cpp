#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        
        int addTarget = max(0, 6 - (int)s.size()), deleteTarget = max(0, (int)s.size() - 20);
        int toDelete = 0, toAdd = 0, toReplace = 0, needUpper = 1, needLower = 1, needDigit = 1;
        
        for(int i = 0, j = 0; i < s.size(); i++) {
        	if(s[i] >= 'a' && s[i] <= 'z') needLower = 0;
        	else if(s[i] >= 'A' && s[i] <= 'Z') needUpper = 0;
        	else if(s[i] >= '0' && s[i] <= '9') needDigit = 0;
        	
        	if(i - j == 2) {
        		if(s[j] == s[j + 1] && s[j + 1] == s[i]) {
        			if(toAdd < addTarget) {
        				toAdd++;
        				j = i;
					}else {
						toReplace++;
						j = i + 1;
					}
				}else {
					j++;
				}
			}
		}
		
		if(s.size() <= 20) return max(addTarget + toReplace, needUpper + needLower + needDigit);
		
		toReplace = 0;
		vector<unordered_map<int, int> > lenCounts(3);
		for(int i = 0, j = 0; i <= s.size(); i++) {
			if(i == s.size() || s[i] != s[j]) {
				int len = i - j;
				if(len > 2) lenCounts[len % 3][len]++;
				j = i;
			}
		}
		
		for(int i = 0, numLetters, dec; i < 3; i++) {
			for(auto it = lenCounts[i].begin(); it != lenCounts[i].end(); it++) {
				if(i < 2) {
					numLetters = i + 1;
					dec = min(it->second, (deleteTarget - toDelete) / numLetters);
					toDelete += dec * numLetters;
					it->second -= dec;
					
					if(it->first - numLetters > 2) {
						lenCounts[2][it->first - numLetters] += dec;
					}
				}
				toReplace += (it->second) * ((it->first) / 3);
			}
		}
		
		int dec = (deleteTarget - toDelete) / 3;
		toReplace -= dec;
		toDelete -= dec * 3;
		
		return deleteTarget + max(toReplace, needUpper + needLower + needDigit);
        
    }
};

int main() {
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->strongPasswordChecker(s);
	
	return 0;
}
