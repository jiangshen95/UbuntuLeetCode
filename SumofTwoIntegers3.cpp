#include<iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
        
    }
};

int main() {
	
	int a, b;
	cin>>a>>b;
	
	Solution *solution = new Solution();
	cout<<solution->getSum(a, b);
	
	return 0;
	
}
