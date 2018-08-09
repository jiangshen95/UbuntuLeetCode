#include<iostream>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
    	if(num.size() < 3) return false;
    	int num1 = 0, num2 = 0;
        for(int i = 0;i < num.size() - 2;i++) {
        	if(i > 0 && num[0] == '0') break;
        	num1 = num1 * 10 + num[i] - '0';
        	num2 = 0;
        	for(int j = i + 1;j < num.size() - 1;j++) {
        		if(j > i + 1 && num[i + 1] == '0') break;
        		num2 = num2 * 10 + num[j] - '0';
        		if(isAdditiveNumber(num1, num2, j + 1, num)) return true;
			}
		}
		
		return false;
    }
    
    bool isAdditiveNumber(int num1, int num2, int index, string num) {
    	if(index >= num.size()) return true;
    	int num3 = 0;
    	for(int i = index;i < num.size();i++) {
    		if(i > index && num[index] == '0') break;
    		num3 = num3 * 10 + num[i] - '0';
    		if(num3 == num1 + num2) {
    			return isAdditiveNumber(num2, num3, i + 1, num);
			}
		}
		return false;
	}
};

int main() {
	
	string num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isAdditiveNumber(num) ? cout<<"True" : cout<<"False";
	
	return 0;
	
}
