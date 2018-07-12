#include<iostream>
#include<math.h>
#include<algorithm> 
#include<vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        int res = n, num = 2;
        while(num * num <= n) {
        	int a = n / (num * num), b = n % (num * num);
        	res = min(res, a + numSquares(b));
        	num ++;
		}
		
		return res;
        
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->numSquares(n);
	
	return 0;
	
}
