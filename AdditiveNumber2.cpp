#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
    	if(num.size() < 3) return false;
    	string num1, num2;
        for(int i = 0;i < num.size() - 2;i++) {
        	if(i > 0 && num[0] == '0') break;
        	num1 = num.substr(0, i + 1);
        	for(int j = i + 1;j < num.size() - 1;j++) {
        		if(j > i + 1 && num[i + 1] == '0') break;
        		num2 = num.substr(i + 1, j - i);
        		if(isAdditiveNumber(num1, num2, j + 1, num)) return true;
			}
		}
		
		return false;
    }
    
    bool isAdditiveNumber(string num1, string num2, int index, string num) {
    	string sum;
    	for(int i = index;i < num.size();i += sum.size()) {
    		sum = add(num1, num2);
    		num1 = num2;
    		num2 = sum;
    		if(num.substr(i, sum.size()) != sum) return false;
		}
		return true;
	}
	
	string add(string n, string m) {
		string sum = "";
		int carry = 0;
		int i = n.size() - 1, j = m.size() - 1;
		while(i >= 0 || j >= 0) {
			carry = (i >= 0 ? n[i] - '0' : 0) + (j >= 0 ? m[j] - '0' : 0) + carry;
			sum += carry % 10 + '0';
			i--;
			j--;
			carry /= 10;
		}
		if(carry > 0) sum += carry + '0';
		reverse(sum.begin(), sum.end());
		
		return sum;
	}
};

int main() {
	
	string num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isAdditiveNumber(num) ? cout<<"True" : cout<<"False";
	
	return 0;
	
}
