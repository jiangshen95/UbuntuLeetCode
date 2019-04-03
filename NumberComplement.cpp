#include<iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int result = 0;
		long mask = 1;
        while(mask <= num) {
        	result |= (num & mask) ^ mask;
        	mask <<= 1;
		}
		
		return result;
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->findComplement(num);
	
	return 0;
	
}
