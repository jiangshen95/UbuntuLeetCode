#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        return longestSubstring(s, 0, s.size() - 1, k);
        
    }
    
    int longestSubstring(string s, int start, int end, int k) {
    	
    	vector<int> m(26, 0);
    	for(int i = start; i <= end; i++) {
    		m[s[i] - 'a']++;
		}
		
		for(int i = 0; i < 26; i++) {
			if(m[i] > 0 && m[i] < k) {
				for(int j = start; j <= end; j++) {
					if(i + 'a' == s[j]) {
						int left = longestSubstring(s, start, j - 1, k);
						int right = longestSubstring(s, j + 1, end, k);
						return max(left, right);
					}
				}
			}
		}
		
		return end - start + 1;
    	
	}
};

int main() {
	
	string s;
	cin>>s;
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	cout<<solution->longestSubstring(s, k)<<endl;
	
	return 0;
}
