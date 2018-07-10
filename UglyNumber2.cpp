#include<iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	
    	if(num == 0) return false;
        
        while(num != 1) {
        	if(num % 2 == 0) num /= 2;
        	else if(num % 3 == 0) num /= 3;
        	else if(num % 5 == 0) num /= 5;
        	else return false;
		}
		
		return true;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isUgly(num) ? cout<<"True" : cout<<"False";
	
	return 0;
	
}
