#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	
    	if(n == 0) return 1;
    	
    	int s = 0;
    	
    	for(int i = 1; i <= n; i++) s += count(i);
    	
    	return s;
    	
    }
    
    int count(int k) {
    	if(k <= 0) return 0;
    	if(k == 1) return 10;
    	int s = 1;
    	for(int i = 1; i < k; i++) s *= (10 - i);
		s *= 9;
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
