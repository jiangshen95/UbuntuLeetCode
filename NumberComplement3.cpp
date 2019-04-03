#include<iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long i = 1;
        while(i <= num) {
        	i <<= 1;
		}
		return (i - 1) ^ num;
//		return (i - 1) - num;
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->findComplement(num);
	
	return 0;
	
}
