#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int l = 1, r = n;
        int time = 1, diff = 1;
        while(l < r) {
        	if(time % 2 == 1) {
        		l += diff;
        		if(n % 2 != 0) r -= diff;
			}else {
				r -= diff;
				if(n % 2 != 0) l += diff;
			}
			time++;
			diff *= 2;
			n /= 2;
		}
        
        return l;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->lastRemaining(n);
	
	return 0;
	
}
