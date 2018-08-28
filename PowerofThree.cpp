#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
    	if(n == 0) return false;
        while(n %3 == 0) n /= 3;
        return n == 1;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	solution->isPowerOfThree(n) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
