#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
    	if(n <= 0) return false;
    	float t = log(n) / log(3);
    	return pow(3, (int)t) == n;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	solution->isPowerOfThree(n) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
