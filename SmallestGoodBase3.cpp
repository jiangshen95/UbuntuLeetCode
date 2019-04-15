#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = 0;
        for(char c : n) num = num * 10 + c - '0';
        long long x = 1;
        for(int i = 62; i >= 2; i--) {
//        	if((x << (i - 1)) > num) continue;
        	if((x << i) - 1 > num) continue;
        	long long left = pow(num + 1, 1.0 / i), right = pow(num, 1.0 / (i - 1)) + 1;
        	while(left < right) {
        		long long mid = left + (right - left) / 2, sum = 0;
        		for(int j = 0; j < i; j++) {
        			sum = sum * mid + 1;
				}
				if(sum == num) return to_string(mid);
				else if(sum < num) left = mid + 1;
				else right = mid - 1;
			}
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
