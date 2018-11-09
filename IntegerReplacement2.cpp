#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        unordered_map<int, int> m;
        return integerReplacement(m, n);
    }
    
    int integerReplacement(unordered_map<int, int>& m, int n) {
    	if(m.find(n) != m.end()) return m[n];
    	if(n == 1) return 0;
    	int res = 0;
    	if(n % 2 == 0) {
    		res = 1 + integerReplacement(n / 2);
		}
        else {
        	res = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
		}
		m[n] = res;
		return res;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->integerReplacement(n);
	
	return 0;
	
}
