/*
*  Time Limit Exceeded
*/
#include<iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        
        int count = 0, num = 0;
        while(count < n) {
        	num ++;
        	if(isUgly(num)) count ++;
		}
        
        return num;
    }
    
    bool isUgly(int num) {
    	
    	for(int i=2;i<=6&&num;i++) {
    		while(num % i == 0)
    			num /= i;
		}
		
		return num == 1;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->nthUglyNumber(n);
	
	return 0; 
	
}
