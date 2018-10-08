#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long x = num;
        while(x * x > num) {
        	x = (x + num / x) / 2;
		}
		
		return x * x == num;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isPerfectSquare(num) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
