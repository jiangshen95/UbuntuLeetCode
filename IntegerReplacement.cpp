#include<iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(n % 2 == 0) return 1 + integerReplacement(n / 2);
        else return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->integerReplacement(n);
	
	return 0;
	
}
