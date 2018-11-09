#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int i = 0, result = 0;
        while(i + k <= s.size()) {
        	
        	vector<int> m(26, 0);
        	int mask = 0, max_index = i;
			for(int j = i; j < s.size(); j++) {
				int t = s[j] - 'a';
				m[t]++;
				if(m[t] < k) mask |= 1 << t;
				else mask &= ~(1 << t);
				
				if(mask == 0) {
					result = max(result, j - i + 1);
					max_index = j;
				} 
			}
			
			i = max_index + 1;
		}
		
		return result;
        
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
