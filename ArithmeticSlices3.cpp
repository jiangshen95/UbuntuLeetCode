#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	int sum = 0;
    	slices(A, A.size() - 1, sum);
    	return sum;
    }
    
    int slices(vector<int>& A, int i, int& sum) {
    	if(i < 2) return 0;
    	int ap = 0;
    	if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
    		ap = 1 + slices(A, i - 1, sum);
    		sum += ap;
		}else slices(A, i - 1, sum);
		
		return ap;
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
