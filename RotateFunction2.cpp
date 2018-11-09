#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        /*
        ** F(0) = 0A + 1B + 2C + 3D
        ** F(1) = 0D + 1A + 2B + 3C
        ** F(2) = 0C + 1D + 2A + 3B
        ** F(3) = 0B + 1C + 2D + 3A 
        ** F(1) = F(0) + sum - 4D
        ** F(2) = F(1) + sum - 4C
        ** ...
    	*/
    	int n = A.size();
    	int sum = 0, f = 0;
		for(int i = 0; i < n; i++) {
			sum += A[i];
			f += i * A[i];
		} 
		
//		int res = f;
//		for(int i = 1; i < n; i++) {
//			f = f + sum - n * A[n - i];
//			res = max(res, f);
//		}

		int res = f;
		for(int i = 1; i < n; i++) {
			f = f - sum + n * A[i - 1];
			res = max(res, f);
		}
		
		return res;
        
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
	cout<<solution->maxRotateFunction(A);
	
	return 0;
	
}
