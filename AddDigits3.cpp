#include<iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
    	
    	//return num == 0 ? 0 : (num % 9 == 0 ? 9 : num % 9);
    	
    	return 1 + (num - 1) % 9;
    }
};

int main() {
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->addDigits(num);
	
	return 0;
}
