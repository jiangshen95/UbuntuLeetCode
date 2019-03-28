/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return findMaxForm(strs, 0, m, n);
    }
    
    int findMaxForm(vector<string>& strs, int pos, int m, int n) {
    	int max_count = 0;
    	for(int i =pos; i < strs.size(); i++) {
    		int o_count = 0, z_count = 0;
    		for(char ch : strs[i]) {
    			if(ch == '0') z_count++;
    			else o_count++;
			}
			
			if(m >= z_count && n >= o_count) {
				max_count = max(max_count, findMaxForm(strs, i + 1, m - z_count, n - o_count) + 1);
			}
		}
		return max_count;
	}
};

int main() {
	int m, n;
	cin>>n;
	
	vector<string> strs;
	for(int i = 0; i < n; i++) {
		string str;
		cin>>str;
		strs.push_back(str);
	}
	
	cin>>m>>n;
	
	Solution *solution = new Solution();
	cout<<solution->findMaxForm(strs, m, n);
	
	return 0;
}
