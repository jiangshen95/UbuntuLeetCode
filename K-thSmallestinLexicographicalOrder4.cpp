#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
    	return helper(n, k, 0);
    }
    
    int getCount(int n, long long prefix) {
    	
    	int count = 0, x = 1;
    	while(prefix <= n) {
    		count += x;
    		prefix *= 10;
    		x *= 10;
		}
		if(n < (prefix / 10 + x / 10 - 1)) count -= x / 10 - (n - prefix / 10 + 1);
		
		return count;
	}
    
    int helper(int n, int k, int prefix) {
    	
    	for(int i = (prefix == 0 ? 1 : 0); i < 10; i++) {
    		int num = getCount(n, prefix * 10 + i);
			if(k <= num) {
				if(k == 1) return prefix * 10 + i;
				else return helper(n, k - 1, prefix * 10 + i);
			}else {
				k -= num;
			}
		}
		return 0;
    	
	}
};

int main() {
	int n, k;
	cin>>n>>k;
	
	Solution *solution = new Solution();
	cout<<solution->findKthNumber(n, k);
	
	return 0;
}
