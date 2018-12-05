#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long long a, b, c;
		a = b = c = LLONG_MIN;
        for(int num : nums) {
        	if(num == a || num == b || num == c) continue;
        	if(num > a) {
        		c = b;
        		b = a;
        		a = num;
			}else if(num > b) {
				c = b;
				b = num;
			}else if(num > c) c = num;
        	cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
		}
        cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
        return c != LLONG_MIN ? c : a;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->thirdMax(nums);
	
	return 0;
	
}
