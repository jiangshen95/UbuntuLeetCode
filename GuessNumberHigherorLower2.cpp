#include<iostream>

using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
    	int l = 1, r = n;
    	while(l <= r) {
    		int mid1 = l + (r - l) / 3;
    		int mid2 = r - (r - l) / 3;
    		int res1 = guess(mid1);
    		int res2 = guess(mid2);
    		if(res1 == 0) return mid1;
    		if(res2 == 0) return mid2;
    		if(res1 == -1) r = mid1 - 1;
    		else if(res2 == -1) {
    			l = mid1 + 1;
    			r = mid2 - 1;
			}else {
				l = mid2 + 1;
			}
		}
		return -1;
    }
};
