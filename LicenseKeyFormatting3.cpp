#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result = "";
        for(int i = S.size() - 1; i >= 0; i--) {
        	if(S[i] != '-') {
        		((result.size() % (K + 1) - K) ? result : result += '-') += toupper(S[i]);
			}
		}
		return string(result.rbegin(), result.rend());
        
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
