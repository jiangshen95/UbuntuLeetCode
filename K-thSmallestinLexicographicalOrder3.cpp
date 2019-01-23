#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
    	int depth = getDepth(n);
    	return helper(n, k, 0, depth);
    }
    
    int getDepth(int n) {
    	int depth = 0;
    	while(n > 0) {
    		n /= 10;
    		depth++;
		}
		return depth;
	}
	
	int getFullTreeNum(int depth) {
		int count = 0, n = 1;
		while(depth > 0) {
			count += n;
			n *= 10;
			depth--;
		}
		return count;
	}
	
	int getMin(int prefix, int depth) {
		while(depth > 0) {
			prefix *= 10;
			depth--;
		}
		return prefix;
	}
	
	int getMax(int prefix, int depth) {
		while(depth > 0) {
			prefix *= 10;
			prefix += 9;
			depth--;
		}
		return prefix;
	}
    
    int helper(int n, int k, int prefix, int depth) {
    	
    	int num1 = getFullTreeNum(depth), num2 = getFullTreeNum(depth - 1);
    	
    	for(int i = (prefix == 0 ? 1 : 0); i < 10; i++) {
    		int num = 0;
    		if(getMax(prefix * 10 + i, depth - 1) <= n) num = num1;
    		else if(getMin(prefix * 10 + i, depth - 1) > n) num = num2;
    		else {
    			num = num2 + (n - getMin(prefix * 10 + i, depth - 1) + 1);
			}
			if(k <= num) {
				if(k == 1) return prefix * 10 + i;
				else return helper(n, k - 1, prefix * 10 + i, depth - 1);
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
