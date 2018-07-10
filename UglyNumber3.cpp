#include<iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	
    	for(int i=2;i<=6&&num;i++) {
    		while(num % i == 0)
    			num /= i;
		}
		
		return num == 1;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isUgly(num) ? cout<<"True" : cout<<"False";
	
	return 0;
	
}
