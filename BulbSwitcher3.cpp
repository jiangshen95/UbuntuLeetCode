#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
    	
    	return sqrt(n);
    	
    }
};

int main() {
	
//	Solution *solution = new Solution();
//	
//	for(int i = 2; i <= 30; i++) {
//		cout<<i<<": "<<solution->bulbSwitch(i)<<endl;
//	}
	
	int n;
	cin>>n;
	Solution *solution = new Solution();
	cout<<solution->bulbSwitch(n);
	return 0;
}
