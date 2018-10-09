#include<iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        
        if(b == 0) return a;
        
        int sum = a ^ b;
        int carry = (a & b) << 1;
        
        return getSum(sum, carry);
        
    }
};

int main() {
	
	int a, b;
	cin>>a>>b;
	
	Solution *solution = new Solution();
	cout<<solution->getSum(a, b);
	
	return 0;
	
}
