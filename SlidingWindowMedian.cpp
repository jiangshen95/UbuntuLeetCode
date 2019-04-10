#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<double> result;
        multiset<int>::iterator median;
        for(int i = 0; i < nums.size(); i++) {
        	if(window.size() < k) window.insert(nums[i]);
			if(window.size() == 1) median = window.begin();
			else if(window.size() % 2 == 1 && nums[i] >= *median) median = next(median);
			else if(window.size() % 2 == 0 && nums[i] < *median) median = prev(median);
			
			for(int w : window) cout<<w<<" ";
			cout<<endl;
			cout<<"media: "<<*median<<endl;
			
			if(window.size() == k) {
				if(k & 1) result.push_back(*median);
				else {
					double t = (double)*median;
					t += *next(median);
					t /= 2;
					result.push_back(t);
				}
				if(k == 1) {
					window.erase(nums[i]);
					continue;
				}
				if(k & 1 && nums[i - k + 1] >= *median) median = prev(median);
				else if(!(k & 1) && nums[i - k + 1] <= *median) median = next(median);
				if(nums[i - k + 1] == *median) {
					if(k & 1) window.erase(next(median));
					else window.erase(prev(median));
				}
				else window.erase(window.find(nums[i - k + 1]));
			}
		}
		return result;
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
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<double> result = solution->medianSlidingWindow(nums, k);
	
	for(double m : result) cout<<m<<" ";
	
	return 0;
}
