#include<iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x || y) {
        	count += (x ^ y) & 1;
        	x >>= 1;
        	y >>= 1;
		}
		return count;
    }
};

int main() {
	int x, y;
	cin>>x>>y;
	
	Solution *solution = new Solution();
	cout<<solution->hammingDistance(x, y);
	
	return 0;
} 
