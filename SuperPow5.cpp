#include<iostream>
#include<vector>

using namespace std;

class Solution {
	
	const int base = 1337;
	
public:
	
	int superPow(int a, vector<int> b, int prime) {
		
		if(!(a %= prime)) return 0;
		int e = 0, mod = prime - 1;
		for(int d : b) {
			e = (e * 10 + d) % mod;
		}
		
		int pow = 1;
		while(e) {
			if(e & 1) {
				pow = pow * a % prime;
			}
			a = a * a % prime;
			e >>= 1;
		}
		
		return pow;
		
	}
	
    int superPow(int a, vector<int>& b) {
        // 1337 = 7 * 171   x % 7 = u    x % 191 = w   x = (764u + 574w) % 1337
        return (764 * superPow(a, b, 7) + 574 * superPow(a, b, 191)) % base;
        
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
