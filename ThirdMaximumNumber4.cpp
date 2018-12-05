#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        int a, b, c;
		a = b = c = INT_MIN;
		int count = 0;
        for(int num : nums) {
        	if(count > 0 && num == a || count > 1 && num == b) continue;
        	if(num > a) {
        		c = b;
        		b = a;
        		a = num;
        		count++;
			}else if(num > b) {
				c = b;
				b = num;
				count++;
			}else if(num >= c) {
				c = num;
				count++;
			}
        	cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
		}
        cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
        return count >= 3 ? c : a;
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
