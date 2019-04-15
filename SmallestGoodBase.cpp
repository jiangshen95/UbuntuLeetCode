#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = 0;
        for(char c : n) num = num * 10 + c - '0';
        for(int i = log(num + 1) / log(2); i >= 2; i--) {
//        	long long left = 2, right = pow(num, 1.0 / (i - i)) + 1;
        	long long left = pow(num + 1, 1.0 / i), right = pow(num, 1.0 / (i - 1)) + 1;
        	while(left < right) {
        		long long mid = left + (right - left) / 2, sum = 0;
        		for(int j = 0; j < i; j++) {
        			sum = sum * mid + 1;
				}
				cout<<"mid: "<<mid<<endl;
				cout<<"sum: "<<sum<<endl;
				if(sum == num) return to_string(mid);
				else if(sum < num) left = mid + 1;
				else right = mid;
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
