#include<iostream>

using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
    	int l = 1, r = n;
    	int mid = l + (r - l) / 2;
    	while(guess(mid) != 0) {
    		if(guess(mid) == 1) l = mid + 1;
    		else r = mid - 1;
    		mid = l + (r - l) / 2;
		}
		
		return mid;
    }
};
