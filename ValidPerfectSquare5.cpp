#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        // 完全平方数是一系列奇数的和
		int n = 1;
		while(num > 0) {
			num -= n;
			n += 2;
		}
		
		return num == 0;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isPerfectSquare(num) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
