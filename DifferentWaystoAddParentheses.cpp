#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> oper;
        
        int num = 0;
        for(int i=0;i<input.length();i++){
        	if(input[i] >= '0' && input[i] <= '9') {
        		num = num*10 + (input[i] - '0');
			}else {
				nums.push_back(num);
				oper.push_back(input[i]);
				num = 0;
			}
		}
		nums.push_back(num);
		
		vector<int> result;
		
		computeLocal(nums, oper, result);
		
		return result;
		
    }
    
    void computeLocal(vector<int> nums, vector<char> oper, vector<int>& result) {
    	
    	if(oper.empty()) result.push_back(nums[0]);
    	
    	for(int i = 0;i < oper.size();i++) {
    		//cout<<oper[i]<<endl;
    		vector<int> temp = nums;
    		vector<char> oper2 = oper;
    		if(oper[i] == '+') temp[i + 1] = temp[i] + temp[i + 1];
    		else if(oper[i] == '-') temp[i + 1] = temp[i] - temp[i + 1];
    		else if(oper[i] == '*') temp[i + 1] = temp[i] * temp[i + 1];
    		oper2.erase(oper2.begin() + i);
    		temp.erase(temp.begin() + i);
    		computeLocal(temp, oper2, result);
		}
    	
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
