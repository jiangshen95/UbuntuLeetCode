#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	if(A.size() < 3) return 0;
    	int count = 0;
    	for(int i = 0; i < A.size() - 2; i++) {
    		int d = A[i + 1] - A[i];
    		for(int j = i + 2; j < A.size(); j++) {
    			if(A[j] - A[j - 1] == d) count++;
    			else break;
			}
		}
        return count;
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
