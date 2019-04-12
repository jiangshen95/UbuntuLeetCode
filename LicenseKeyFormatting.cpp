/*
 * Memory Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result = "";
        int count = 0;
        for(int i = S.size() - 1; i >= 0; i--) {
        	char c = S[i];
        	if(c == '-') continue;
        	if(c >= 'a' && c <= 'z') c -= 32;
        	if(count++ == K) {
        		result = "-" + result;
        		count = 1;
			}
			result = c + result;
		}
		return result;
    }
};

int main() {
	
	string S;
	cin>>S;
	
	int K;
	cin>>K;
	
	Solution *solution = new Solution();
	cout<<solution->licenseKeyFormatting(S, K);
	
	return 0;
}
