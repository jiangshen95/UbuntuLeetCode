#include<iostream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int a = 0, b = 0;
        for(int i=0;i<secret.size();i++) {
        	
        	if(secret[i] == guess[i]) {
        		a ++;
        		secret[i] = 'a';
        		guess[i] = 'b';
			}
        	
		}
		
		for(int i=0;i<guess.size();i++) {
			for(int j=0;j<secret.size();j++) {
				if(guess[i] == secret[j]) {
					b ++;
					secret[j] = 'a';
					break;
				}
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
