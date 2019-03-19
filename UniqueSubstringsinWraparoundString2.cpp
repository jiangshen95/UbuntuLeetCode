#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        
        int len = 1;
        vector<int> counts(26, 0);
        
        for(int i = 1; i <= p.size(); i++) {
        	if(i < p.size() && ((p[i - 1] == 'z' && p[i] == 'a') || p[i] == p[i - 1] + 1)) len++;
        	else {
        		len = 1;
			}
			counts[p[i - 1] - 'a'] = max(len, counts[p[i - 1] - 'a']);
		}
		
		int result = 0;
		for(int count : counts) result += count;
		
		return result;
    }
};

int main() {
	string p;
	cin>>p;
	
	Solution *solution = new Solution();
	cout<<solution->findSubstringInWraproundString(p);
	
	return 0;
}
