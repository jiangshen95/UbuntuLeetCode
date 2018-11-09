#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        int step = 0;
		while(n != 1) {
			if((n & 1) == 0) n >>= 1;
			//else if(n == 3 || ((n >> 1) & 1) == 0) n--;
			else if(n == 3 || (n + 1) % 4 != 0) n--;
			else {
				if(n == INT_MAX) {
					step++;
					n = n >> 1 + 1;
				}else {
					n++;
				}
			}
			step++;
		} 
		return step;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->integerReplacement(n);
	
	return 0;
	
}
