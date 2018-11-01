#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        vector<vector<int> > m(26);
        
        for(int i = 0; i < t.size(); i++) {
        	m[t[i] - 'a'].push_back(i);
		}
		
		int pre = 0;
		for(char c : s) {
			if(m[c - 'a'].empty()) return false;
			int index = binarySearch(m[c - 'a'], pre);
			cout<<index<<endl;
			if(index >= m[c - 'a'].size()) return false;
			pre = m[c - 'a'][index] + 1;
		}
        
        return true;
    }
    
    int binarySearch(vector<int> nums, int target) {
    	int l = 0, r = nums.size() - 1;
    	while(l <= r) {
    		int mid = l + (r - l) / 2;
    		if(nums[mid] >= target) r = mid - 1;
    		else l = mid + 1;
		}
		return l;
	}
};

int main() {
	
	string s, t;
	cin>>s;
	cin>>t;
	
	Solution *solution = new Solution();
	solution->isSubsequence(s, t) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
