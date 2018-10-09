#include<iostream>
#include<vector>

using namespace std;

class Solution {
	
	const int base = 1337;
	
public:
    int superPow(int a, vector<int>& b) {
        
        //phi(1337) = phi(7)*phi(191) = 6 * 190 = 1140
        int digit = 0;
        for(int d : b) {
        	digit = (digit * 10 + d) % 1140;
		}
		
		if(digit == 0) digit = 1140;
		
		int result = 1;
		a %= base;
		for(int i = 0; i < digit; i++) {
			result *= a;
			result %= base;
		}
		
		return result;
        
    }
};

int main() {
	
	int n;
	cin>>n;
	
	int a;
	cin>>a;
	
	vector<int> b;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		b.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->superPow(a, b);
	
	return 0;
	
} 
