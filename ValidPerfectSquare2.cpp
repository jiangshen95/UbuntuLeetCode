#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long half = num, t = half * half;
        
        while(t > num) {
        	half /= 2;
        	t = half * half;
		}
		
		for(int i = half; i <= half * 2; i++) {
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
