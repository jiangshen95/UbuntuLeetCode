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
		
		return computeLocal(nums, oper);
		
    }
    
    vector<int> computeLocal(vector<int> nums, vector<char> oper) {
    	
    	if(oper.empty()) {
    		return vector<int>(1, nums[0]);
		}
    	
    	vector<int> result;
    	
    	for(int i = 0;i < oper.size();i++) {
    		vector<int> front = computeLocal(vector<int>(nums.begin(), nums.begin() + i + 1), vector<char>(oper.begin(), oper.begin() + i));
    		vector<int> back = computeLocal(vector<int>(nums.begin() + i + 1, nums.end()), vector<char>(oper.begin() + i + 1, oper.end()));
    		
    		if(oper[i] == '+') {
    			for(int j = 0;j < front.size();j++){
    				for(int k = 0;k < back.size();k++){
    					result.push_back(front[j] + back[k]);
					}
				}
			}else if(oper[i] == '-'){
				for(int j = 0;j < front.size();j++){
    				for(int k = 0;k < back.size();k++){
    					result.push_back(front[j] - back[k]);
					}
				}
			}else if(oper[i] == '*'){
				for(int j = 0;j < front.size();j++){
    				for(int k = 0;k < back.size();k++){
    					result.push_back(front[j] * back[k]);
					}
				}
			}
    		
		}
		
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
