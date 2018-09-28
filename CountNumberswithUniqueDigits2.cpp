#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	
    	if(n == 0) return 1;
    	
    	int s = 10, t = 9;
    	
    	for(int i = 2; i <= n; i++) {
    		t *= (11 - i);
    		s += t;
		}
    	
    	return s;
    	
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->countNumbersWithUniqueDigits(n);
	
	return 0;
	
}
