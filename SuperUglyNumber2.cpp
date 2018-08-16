#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<int> nums(1, 1);
        vector<int> where(primes.size(), 0);
        while(nums.size() < n) {
        	int u = 0;
        	int num = INT_MAX;
	        for(int i = 0; i < primes.size(); i++) {
	        	if(primes[i] * nums[where[i]] < num) {
	        		num = primes[i] * nums[where[i]];
	        		u = i;
				}
			}
			where[u]++;
			if(num > nums.back()) {
				cout<<num<<endl;
				nums.push_back(num);
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
