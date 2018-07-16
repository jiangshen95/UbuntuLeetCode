#include<iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        
        return n % 4;
        
    }
};

int main() {
	int n;
	cin>>n;
	Solution *solution = new Solution();
	solution->canWinNim(n) ? cout<<"true" : cout<<"false";
	
	return 0;
}
