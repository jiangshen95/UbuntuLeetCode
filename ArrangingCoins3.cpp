#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        
        long long l = 1, r = n;
        
        while(l <= r) {
        	long long mid = l + (r - l) / 2;
        	if(mid * (mid + 1) / 2 <= n) l = mid + 1;
        	else r = mid - 1;
		}
		
		return l - 1;
    }
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->arrangeCoins(n);
	
	return 0;
}
