#include<iostream>
#include<math.h> 
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
    	int upper = pow(10, n) - 1, lower = upper - pow(10, (n + 1) >> 1);
    	auto cmp = [](pair<int, int> a, pair<int, int> b) {
    		return (long long)a.first * a.second < (long long)b.first * b.second;
		};
    	priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> p(cmp);
    	
    	for(int i = upper; i > lower; i--) {
    		int r = i % 10;
    		if(r == 3 || r == 7) {
    			p.push(make_pair(i, i));
			}else if(r == 1) {
				p.push(make_pair(i, i - 2));
			}else if(r == 9) {
				p.push(make_pair(i, i - 8));
			}
		}
		
		while(!p.empty()) {
			pair<int, int> a = p.top(); p.pop();
			long long num = (long long)a.first * a.second;
			if(isPalindrome(num)) return num % 1337;
			if(a.second > lower) {
				a.second -= 10;
				p.push(a);
			}
		}
		
		return 0;
    }
    
    bool isPalindrome(long long n) {
    	long long r = 0;
    	for(long long x = n; x > 0; r = r * 10 + x % 10, x /= 10);
    	return r == n;
	}
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->largestPalindrome(n);
	
	return 0;
}
