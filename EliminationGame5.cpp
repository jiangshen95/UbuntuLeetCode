#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
    	/*
    	** ������ⷨ�ķǵݹ���ʽ���ѵݹ�ת����ջ 
    	*/
        vector<int> stack;
		while(n > 1) {
			stack.push_back(n / 2);
			n /= 2;
		} 
		
		int result = 1;
		while(!stack.empty()) {
			result = 2 * (stack.back() + 1 - result);
			stack.pop_back();
		}
		
		return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->lastRemaining(n);
	
	return 0;
	
}
