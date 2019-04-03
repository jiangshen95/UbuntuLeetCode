#include<iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while(num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->findComplement(num);
	
	return 0;
	
}
