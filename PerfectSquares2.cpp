#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        //四平方和定理 
        while(n % 4 == 0) {
        	n /= 4;
		}
		
		if(n % 8 == 7) return 4;
		
		for(int i=0;i<=sqrt(n);i++) {
			int j = sqrt(n - i * i);
			if(j * j == n - i * i){
				return i == 0 || j == 0 ? 1 : 2; //return !!i + !!j;  都为正数返回2，有一个正数返回1 
			}
		}
		
		return 3;
        
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->numSquares(n);
	
	return 0;
	
}
