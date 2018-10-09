#include<iostream>
#include<vector>

using namespace std;

class Solution {
	
	const int base = 1337;
	vector<int> findLoop(int a) {
		
		vector<int> index;
		vector<bool> set(base, false);
		int rem = a % base;
		while(!set[rem]) {
			set[rem] = true;
			index.push_back(rem);
			rem = (rem * a) % base;
		}
		
		return index;
	} 
	
	int modBy(vector<int> b, int n) {
		int rem = 0;
		for(int i = 0; i < b.size(); i++) {
			rem = (rem * 10 + b[i]) % n;
		}
		
		return rem;
	}
	
public:
    int superPow(int a, vector<int>& b) {
        
        if(a > base) a %= base;
        
        vector<int> index = findLoop(a);
        int loopsize = index.size();
        int rem = modBy(b, loopsize);
        rem = rem == 0 ? loopsize : rem;
        return index[rem - 1];
        
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
