#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
    	
    	vector<int> count(26, 0);
    	
    	int maxCount = 0, result = 0, start = 0;
    	for(int end = 0; end < s.size(); end++) {
    		maxCount = max(maxCount, ++count[s[end] - 'A']);
    		if(end - start + 1 - maxCount > k) {
    			count[s[start] - 'A']--;
    			start++;
			}
    		result = max(result, end - start + 1);
		}
		
		return result;
    	
    }
};

int main() {
	string s;
	int k;
	cin>>s;
	cin>>k;
	
	Solution *solution = new Solution();
	cout<<solution->characterReplacement(s, k);
	
	return 0;
}
