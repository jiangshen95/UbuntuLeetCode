#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        for(int i = 1; i <= num / i; i++) {
        	if(i * i == num) return true;
		}
		
		return false;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isPerfectSquare(num) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
