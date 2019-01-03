#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        
        int addTarget = max(0, 6 - (int)s.size()), deleteTarget = max(0, (int)s.size() - 20);
        int change = 0, needUpper = 1, needLower = 1, needDigit = 1;
        
        int one = 0, two = 0;
        
        for(int i = 0, j = 0; i <= s.size(); i++) {
        	if(i < s.size() && s[i] >= 'a' && s[i] <= 'z') needLower = 0;
        	else if(i < s.size() && s[i] >= 'A' && s[i] <= 'Z') needUpper = 0;
        	else if(i < s.size() && s[i] >= '0' && s[i] <= '9') needDigit = 0;
        	
        	if(i == s.size() || s[i] != s[j]) {
        		int len = i - j;
        		if(len >= 3) {
        			change += len / 3;
        			if(len % 3 == 0) one++;
        			else if(len % 3 == 1) two++;
				}
				j = i;
			}
		}
		
		if(s.size() < 6) return max(addTarget, needUpper + needLower + needDigit);
		else if(s.size() <= 20) {
			return max(change, needUpper + needLower + needDigit);
		}
		else {
			change -= min(one, deleteTarget);
			change -= min(max(deleteTarget - one, 0), two * 2) / 2;
			change -= max(deleteTarget - one - two * 2, 0) / 3;
			
			return deleteTarget + max(change, needUpper + needLower + needDigit);
		}
        
    }
};

int main() {
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->strongPasswordChecker(s);
	
	return 0;
}
