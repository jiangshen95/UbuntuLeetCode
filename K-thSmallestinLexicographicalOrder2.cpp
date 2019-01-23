#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k > 0) {
        	long long step = 0, first = cur, last = cur + 1;
        	while(first <= n) {
        		step += min((long long)n + 1, last) - first;
        		first *= 10;
        		last *= 10;
			}
			
			if(k >= step) {
				k -= step;
				cur++;
			}else {
				k--;
				cur *= 10;
			}
		}
		return cur;
    }
};

int main() {
	int n, k;
	cin>>n>>k;
	
	Solution *solution = new Solution();
	cout<<solution->findKthNumber(n, k);
	
	return 0;
}
