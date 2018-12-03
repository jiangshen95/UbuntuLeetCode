#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	if(A.size() < 3) return 0;
    	int count = 0, result = 0;
    	for(int i = 2; i < A.size(); i++) {
    		if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]) count++;
			else {
				result += count * (1 + count) / 2;
				count = 0;
			}
		}
		result += count * (1 + count) / 2;
		return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> A;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		A.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->numberOfArithmeticSlices(A);
	
	return 0;
	
}
