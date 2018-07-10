#include<iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
    	
    	if(num / 10 == 0) return num;
    	
    	int sum = 0;
    	for(;num > 0;num /= 10) sum += num % 10;
    	
    	return addDigits(sum);
    	
    }
};

int main() {
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->addDigits(num);
	
	return 0;
}
