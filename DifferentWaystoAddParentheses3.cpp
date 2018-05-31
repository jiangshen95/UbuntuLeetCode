#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	
    	vector<int> result;
        
        int num = 0;
        for(int i = 0;i < input.length();i++) {
        	if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
        		string p1 = input.substr(0, i);
        		string p2 = input.substr(i + 1, input.size() - i - 1);
        		vector<int> num1 = diffWaysToCompute(p1);
        		vector<int> num2 = diffWaysToCompute(p2);
        		
        		for(int j = 0;j < num1.size();j++) {
        			for(int k = 0;k < num2.size();k++) {
        				if(input[i] == '+') result.push_back(num1[j] + num2[k]);
        				else if(input[i] == '-') result.push_back(num1[j] - num2[k]);
        				else if(input[i] == '*') result.push_back(num1[j] * num2[k]);
					}
				}
			}else {
				num = num * 10 + (input[i] - '0');
			}
		}
		
		if(result.empty()) result.push_back(num);
		
		return result;
		
    }
};

int main() {
	
	string input;
	cin>>input;
	
	Solution *solution = new Solution();
	vector<int> result = solution->diffWaysToCompute(input);
	
	for(int i=0;i<result.size();i++) {
		cout<<result[i]<<" ";
	}
	
	return 0;
	
}
