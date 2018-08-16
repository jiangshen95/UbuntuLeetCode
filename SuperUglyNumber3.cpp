#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<int> nums(n);
        vector<int> index(primes.size(), 0);
        vector<int> val(primes.size(), 1);
        
        int next = 1;
        for(int i = 0; i < n; i++) {
        	
        	nums[i] = next;
        	
        	next = INT_MAX;
        	for(int j = 0; j < primes.size(); j++) {
        		if(val[j] == nums[i]) val[j] = primes[j] * nums[index[j]++];
        		next = min(next, val[j]);
			}
        	
		}
		
		return nums.back();
        
        
    }

};

int main() {
	
	int n;
	cin>>n;
	
	int m;
	cin>>m;
	
	vector<int> primes;
	for(int i = 0; i < m; i++) {
		int prime;
		cin>>prime;
		primes.push_back(prime);
	}
	
	Solution *solution = new Solution();
	cout<<solution->nthSuperUglyNumber(n, primes);
	
	return 0;
	
}
