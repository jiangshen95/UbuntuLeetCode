#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
    	
        if(n <= 3) return n - 1;
        if(n % 3 == 0) return pow(3, n / 3);
        return n % 3 == 1 ? pow(3, n / 3 - 1) * 4 : pow(3, n / 3) * 2;
		
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->integerBreak(n);
	
	return 0;
	
}
