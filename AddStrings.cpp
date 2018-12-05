#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string sum = "";
		int i1 = num1.size() - 1, i2 = num2.size() - 1;
		int carry = 0;
//		while(i1 >= 0 || i2 >= 0) {
		while(i1 >= 0 || i2 >= 0 || carry > 0) {
			if(i1 >= 0) carry += num1[i1] - '0';
			if(i2 >= 0) carry += num2[i2] - '0';
			sum += '0' + carry % 10;
			carry /= 10;
			i1--; i2--;
		} 
//		if(carry > 0) sum += '0' + carry;
		reverse(sum.begin(), sum.end());
        
        return sum;
    }
};

int main() {
	string num1, num2;
	cin>>num1>>num2;
	
	Solution *solution = new Solution();
	cout<<solution->addStrings(num1, num2);
	
	return 0;
}
