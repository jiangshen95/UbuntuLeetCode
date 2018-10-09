#include<iostream>
#include<vector>

using namespace std;

class Solution {
	
	const int base = 1337;
	int powmod(int a, int t) {
		a %= base;
		int res = 1;
		for(int i = 0; i < t; i++) {
			res *= a;
			if(res > base) res %= base;
		}
		
		return res;
	}
	
public:
    int superPow(int a, vector<int>& b) {
        
        if(b.empty()) return 1;
        
        int last_digit = b.back();
        b.pop_back();
        
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
        
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
