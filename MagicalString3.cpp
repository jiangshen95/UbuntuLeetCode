#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if(n <= 0) return 0;
        if(n <= 3) return 1;
        
        vector<int> s{1, 2, 2};
        int result = 1, head = 2, tail = 3, num = 1;
        while(tail < n) {
        	for(int i = 0; i < s[head]; i++) {
        		s.push_back(num);
        		if(num == 1 && tail < n) result++;
        		tail++;
			}
			num ^= 3;
			head++;
		}
		return result;
    }
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->magicalString(n);
	
	return 0;
}
