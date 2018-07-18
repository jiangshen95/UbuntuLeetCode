#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int a = 0, b = 0;
        
        vector<int> num(10, 0);
        
        for(int i=0;i<secret.size();i++) {
        	
        	int s = secret[i] - '0';
        	int g = guess[i] - '0';
        	
        	if(s == g) a ++;
        	else {
        		if(num[s] < 0) b ++;
        		if(num[g] > 0) b ++;
        		num[s] ++;
        		num[g] --;
			}
        	
		}
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};

int main() {
	
	string secret, guess;
	cin>>secret;
	cin>>guess;
	
	Solution *solution = new Solution();
	cout<<solution->getHint(secret, guess);
	
	return 0;
	
}
