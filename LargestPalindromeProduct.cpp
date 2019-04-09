#include<iostream>
#include<math.h> 

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
    	if(n == 1) return 9;
    	int upper = pow(10, n) - 1, lower = upper / 10;
    	for(int i = upper; i > lower; i--) {
    		int k = i;
    		long long palind = i;
			while(k > 0) {
				palind = palind * 10 + k % 10;
				k /= 10; 
			}
//			cout<<palind<<endl;
			for(long long x = upper; x * x >= palind; x--) {
				if(palind % x == 0) return palind % 1337;
			}
		}
		return 0;
    }
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->largestPalindrome(n);
	
	return 0;
}
