#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int a = 0, b = 0;
        
        vector<int> sVec(10, 0);
        vector<int> gVec(10, 0);
        
        for(int i=0;i<secret.size();i++) {
        	int s = secret[i] - '0';
        	int g = guess[i] - '0';
        	if(s == g) a ++;
        	else {
        		sVec[s] ++;
        		gVec[g] ++;
			}
		}
		
		for(int i=0;i<10;i++) {
			b += min(sVec[i], gVec[i]);
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
