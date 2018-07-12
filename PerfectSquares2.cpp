#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        //��ƽ���Ͷ��� 
        while(n % 4 == 0) {
        	n /= 4;
		}
		
		if(n % 8 == 7) return 4;
		
		for(int i=0;i<=sqrt(n);i++) {
			int j = sqrt(n - i * i);
			if(j * j == n - i * i){
				return i == 0 || j == 0 ? 1 : 2; //return !!i + !!j;  ��Ϊ��������2����һ����������1 
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
