#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        bool hasThird = false, hasIntMin = false;
        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] == INT_MIN) {
        		if(a > INT_MIN && b > INT_MIN) hasThird = true;
        		hasIntMin = true;
        		continue;
			}
        	if(nums[i] == a || nums[i] == b) continue;
        	if(nums[i] > a) {
        		if(a > b) {
        			if((hasIntMin && b == c) || b > c) {
        				c = b;
        				hasThird = true;
					}
        			b = a;
				}
        		a = nums[i];
			}
        	else if(nums[i] > b) {
        		if((hasIntMin && b == c) || b > c) {
        			c = b;
        			hasThird = true;
				}
				b = nums[i];
			}
        	else if(nums[i] >= c) {
        		c = nums[i];
        		hasThird = true;
			}
        	cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
		}
        cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
        return hasThird ? c : a;
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
