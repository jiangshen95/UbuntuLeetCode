#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
    	//return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
    	return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) == num;
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isPowerOfFour(num) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
