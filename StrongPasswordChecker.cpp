#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        
        int types = 0, lower = 0, upper = 0, digits = 0, count = 1;
        vector<int> repeats;
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] >= 'a' && s[i] <= 'z') lower++;
        	else if(s[i] >= 'A' && s[i] <= 'Z') upper++;
        	else if(s[i] >= '0' && s[i] <= '9') digits++;
        	if(i > 0 && s[i] == s[i - 1]) count++;
        	else {
        		if(count >= 3) repeats.push_back(count);
        		count = 1;
			}
		}
		if(count >= 3) repeats.push_back(count);
		
		types = (lower > 0) + (upper > 0) + (digits > 0);
		
		int step = 0;
		if(s.size() < 6) {
			step += 3 - types > 6 - s.size() ? 3 - types : 6 - s.size();
		}else {
			int over = 0, left = 0;
			if(s.size() > 20) over = s.size() - 20;
			step += over;
			
			for(int i = 0; i < repeats.size(); i++) {
				if(over > 0 && repeats[i] % 3 != 2) {
					int t = repeats[i] % 3 + 1;
					if(over - t >= 0) {
						over -= t;
						repeats[i] -= t;
					}
				}
			}
			
			for(int i = 0; i < repeats.size(); i++) {
				if(repeats[i] > 2 && over > 0) {
					int need = repeats[i] - 2;
					repeats[i] -= over;
					over -= need;
				}
				if(repeats[i] > 2) left += repeats[i] / 3;
			}
			
			step += max(left, 3 - types);
		}
        
        return step;
    }
};

int main() {
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->strongPasswordChecker(s);
	
	return 0;
}
