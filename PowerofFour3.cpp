#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
    	return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isPowerOfFour(num) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
