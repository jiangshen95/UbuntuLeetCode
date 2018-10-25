#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
    	/*
    	** 1 2 3 4 5 ... n  结果是i  翻转之后 结果是n + 1 - i（第i个） 
    	*/
        return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->lastRemaining(n);
	
	return 0;
	
}
