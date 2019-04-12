#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int count = 0;
        for(char c : S) count += (c != '-');
        int groups = count / K;
        count = count % K == 0 ? K : count - groups * K;
        string result = "";
        for(char c : S) {
        	if(c == '-') continue;
        	if(c >= 'a' && c <= 'z') c -= 32;
        	if(count-- == 0) {
        		result.push_back('-');
        		count = K - 1;
			}
			result.push_back(c);
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
