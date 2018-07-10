#include<iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        
        if(num == 0) return false;
        if(num == 1) return true;
        
        if(num % 2 == 0) return isUgly(num / 2);
        if(num % 3 == 0) return isUgly(num / 3);
        if(num % 5 == 0) return isUgly(num / 5);
        
        return false;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isUgly(num) ? cout<<"True" : cout<<"False";
	
	return 0;
	
}
