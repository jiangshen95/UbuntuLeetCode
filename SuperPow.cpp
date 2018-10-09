#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        
        int res = 1;
        
        int i = b.size() - 1;
        
        if(a > 1337) a %= 1337;
        
        for(int i = b.size() - 1; i >= 0; i--) {
        	
        	for(int j = 0; j < b[i]; j++) {
        		res *= a;
        		if(res > 1337) res %= 1337;
			}
        	
        	int t = 1;
        	for(int j = 0; j < 10; j++) {
        		t *= a;
        		if(t > 1337) t %= 1337;
			}
			
			a = t;
        	
		}
        
        return res;
        
    }
};

int main() {
	
	int n;
	cin>>n;
	
	int a;
	cin>>a;
	
	vector<int> b;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		b.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->superPow(a, b);
	
	return 0;
	
} 
