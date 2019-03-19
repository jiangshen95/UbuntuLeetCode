#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        
        int len = 0, result = 0;
        vector<int> counts(26, 0);
        
        for(int i = 0; i < p.size(); i++) {
        	int cur = p[i] - 'a';
        	if(i > 0 && (p[i - 1] - 'a' + 1) % 26 != cur) len = 0;
        	if(++len > counts[cur]) {
        		result += len - counts[cur];
        		counts[cur] = len;
			}
		}
		
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
