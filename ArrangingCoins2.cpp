#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        
        return (sqrt(1 + 8 * (long long)n) - 1) / 2;
        
    }
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->arrangeCoins(n);
	
	return 0;
}
