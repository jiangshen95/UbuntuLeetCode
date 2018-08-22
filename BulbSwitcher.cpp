/**
* Time Limit Exceeded
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        if(n == 1) return n;
        vector<bool> bulb(n, true);
        for(int i = 2; i <= n; i++) {
        	for(int j = i - 1; j < n; j += i) bulb[j] = !bulb[j];
		}
		
		int count = 0;
		for(int i = 0; i < n; i++) count += bulb[i];
		
		return count;
    }
};

int main() {
	int n;
	cin>>n;
	Solution *solution = new Solution();
	cout<<solution->bulbSwitch(n);
	return 0;
}
