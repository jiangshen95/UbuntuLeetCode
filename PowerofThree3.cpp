#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
    	return (n > 0 && 1162261467 % n == 0);
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	solution->isPowerOfThree(n) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
