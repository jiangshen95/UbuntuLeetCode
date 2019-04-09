#include<iostream>
#include<math.h> 

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
    	if(n == 1) return 9;
    	int upper = pow(10, n) - 1, lower = upper / 10;
    	
    	long long possibleNum = (long long)upper * upper;
    	
    	int divider = pow(10, n);
    	int left = possibleNum / divider;
    	int right = possibleNum % divider;
    	
    	if(left == reverseNum(right)) return possibleNum % 1337;
    	
    	if(reverseNum(left) > right) left--;
    	
    	possibleNum = (long long)left * divider + reverseNum(left);
    	while(left > lower) {
    		for(long long i = upper; i * i >= possibleNum; i--) {
    			if(possibleNum % i == 0) return possibleNum % 1337;
			}
			left--;
			possibleNum = (long long)left * divider + reverseNum(left);
		}
    	
		return 0;
    }
    
    int reverseNum(int num) {
    	int r = 0;
    	for(; num > 0; r = r * 10 + num % 10, num /= 10);
    	return r;
	}
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->largestPalindrome(n);
	
	return 0;
}
