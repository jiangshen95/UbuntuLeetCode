#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        addOperator("", num, target, result);
        return result;
    }
    
    void addOperator(string pre, string num, int target, vector<string>& result) {
    	
    	int len = num.size();
    	int sum;
    	for(int i=0;i<len;i++) {
    		string num1 = num.substr(0, i);
    		string num2 = num.substr(i, len - i);
    		
    		if(num1.size() > 1 && num1[0] == '0') continue;
    		
    		if(i == 0) {
    			if(num2.size() > 1 && num2[0] == '0') continue; 
    			if(getValue(pre + num2) == target) result.push_back(pre + num2);
			}
    		else {
    			addOperator(pre + num1 + "+", num2, target, result);
    			addOperator(pre + num1 + "-", num2, target, result);
    			addOperator(pre + num1 + "*", num2, target, result);
			}
    		
		}
    	
	}
	
	long getValue(string str) {
		
		vector<long> nums;
		char oper = '+';
		
		long num = 0;
		for(int i=0;i<str.size();i++) {
			if(str[i] >= '0' && str[i] <= '9') {
				num = num * 10 + str[i] - '0'; 
			}else {
				if(oper == '*') {
					nums[nums.size() - 1] = nums.back() * num;
				}else {
					if(oper == '-') num = -num;
					nums.push_back(num);
				}
				oper = str[i];
				num = 0;
			}
		}
		
		long result;
		if(oper == '*') {
			nums[nums.size() - 1] = nums.back() * num;
			result = 0;
		}else {
			if(oper == '-') result = -num;
			else result = num;
		}
		
		for(int i=0;i<nums.size();i++) result += nums[i];
		
		return result;
		
	}
};

int main() {
	
	string num;
	cin>>num;
	int target;
	cin>>target;
	
	Solution *solution = new Solution();
	vector<string> result = solution->addOperators(num, target);
	for(int i=0;i<result.size();i++) {
		cout<<result[i]<<endl;
	}
	
	return 0;
	
}
