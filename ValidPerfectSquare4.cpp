#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int l = 0, r = num;
        while(l <= r) {
        	
        	long mid = l + (r - l) / 2, t = mid * mid;
        	if(t > num) r = mid - 1;
        	else if(t < num) l = mid + 1;
        	else return true;
        	
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
