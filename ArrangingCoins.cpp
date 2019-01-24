#include<iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        
        int count = 0, level = 1;
        while(n >= level) {
        	count++;
        	n -= level;
        	level++;
		}
		
		return count;
        
    }
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->arrangeCoins(n);
	
	return 0;
}
