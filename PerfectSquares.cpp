/*
*  Time Limit Exceeded
*/
#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        int s = sqrt(n);
    	if(s * s == n) {
    		return 1;
		}
		
		int min = n;
		for(int i=s;i>=1;i--) {
			int count = 1 + numSquares(n - i * i);
			if(count < min) min = count;
		}
		
		return min;
        
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->numSquares(n);
	
	return 0;
	
}
