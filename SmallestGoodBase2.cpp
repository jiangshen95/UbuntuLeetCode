#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = 0;
        for(char c : n) num = num * 10 + c - '0';
        for(int i = log(num) / log(2); i >= 2; i--) {
        	long long k = pow(num, 1.0 / i), sum = 0;
        	for(int j = 0; j <= i; j++) sum = sum * k + 1;
        	if(sum == num) return to_string(k); 
		}
		return to_string(num - 1);
    }
};

int main() {
	
	string n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->smallestGoodBase(n);
	
	return 0;
}
