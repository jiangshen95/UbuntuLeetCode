#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int head = 1;
        int step = 1;
        int remaining = n;
        while(remaining > 1) {
        	if(left || remaining % 2 == 1) head += step;
        	step *= 2;
        	remaining /= 2;
        	left = !left;
		}
		
		return head;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->lastRemaining(n);
	
	return 0;
	
}
