#include<iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
    	int sum = 0;
        while(num/10 > 0) {
        	sum = 0;
        	while(num > 0){
        		sum += num%10;
        		num /= 10;
			}
			num = sum;
		}
		
		return num;
    }
};

int main() {
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->addDigits(num);
	
	return 0;
}
