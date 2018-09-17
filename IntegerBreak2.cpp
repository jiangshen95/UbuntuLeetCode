#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n - 1;
        int result = 1;
        while(n > 4) {
        	result *= 3;
        	n -= 3;
		}
		result *= n;
		return result;
		
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->integerBreak(n);
	
	return 0;
	
}
