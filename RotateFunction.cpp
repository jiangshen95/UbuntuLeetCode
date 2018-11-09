/*
** Time Limite Exceeded
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        int n = A.size();
        if(n == 0) return 0;
        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
        	int sum = 0;
        	for(int j = 0; j < n; j++) {
        		sum += j * A[(j + i) % n];
			}
			cout<<sum<<endl;
			res = max(res, sum);
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
