/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        for(int i = 0; i < A.size(); i++)
        	numberOfArithmeticSlices(A, i, 0, 1, result);
        return result;
    }
    
    void numberOfArithmeticSlices(vector<int>& A, int pos, long long diff, int count, int& result) {
    	for(int i = pos + 1; i < A.size(); i++) {
    		if(count > 1 && (long long)A[i] - A[pos] == diff) {
    			result++;
    			numberOfArithmeticSlices(A, i, diff, count + 1, result);
			}
			else if(count <= 1) numberOfArithmeticSlices(A, i, (long long)A[i] - A[pos], count + 1, result);
		}
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	} 
	
	Solution *solution = new Solution();
	cout<<solution->numberOfArithmeticSlices(nums);
	
	return 0;
	
}
