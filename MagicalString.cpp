#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        vector<int> s{1};
        int i = 0, count = 0;
        while(s.size() < n) {
        	int last = s.back();
        	if(s[i] == 1) {
        		s.push_back(3 - last);
        		count++;
			}
        	else {
        		s.push_back(last);
        		s.push_back(3 - last);
			}
			i++;
		}
		for(; i < n; i++)
			if(s[i] == 1) count++;
		return count;
    }
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->magicalString(n);
	
	return 0;
}
