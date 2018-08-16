/*
** Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int count = 0;
        int i = 1;
        while(count < n) {
        	if(isSuperUgly(i++, primes)) count++;
		}
		
		return i - 1;
    }
    
    bool isSuperUgly(int num, vector<int> primes) {
    	while(num > 1) {
    		bool flag = false;
    		for(int i = 0; i < primes.size(); i++) {
    			if(num % primes[i] == 0) {
    				num /= primes[i];
    				flag = true;
				}
			}
			if(!flag)  return false;
		}
		
		return num == 1;
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
